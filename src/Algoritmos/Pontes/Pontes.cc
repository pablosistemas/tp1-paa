#include <algorithm>
#include <iterator>
#include <vector>
#include <memory>
#include <bitset>
#include <stack>
#include <set>

#include "./Pontes.h"
#include "../../Util/Tipos.h"
#include "../../Estruturas/Corredor/Corredor.h"

namespace Algoritmos {
    void Pontes::calcula_pontes (
        std::vector<std::vector<std::shared_ptr<Corredor> > >& lista_adjacencias
    ) {
        auto n = lista_adjacencias.size();
        std::vector<int64_t> dfs_low(n, -1);
        std::vector<int64_t> dfs_num(n, -1);
        std::vector<int64_t> dfs_parent(n, -1);
        std::set<Tipos::vertice_t> pontes;
        int numero_filhos_raiz = 0;
        int contador_dfs = 0;
        articulation_point_and_bridge (
            lista_adjacencias, dfs_low, dfs_num, dfs_parent, 1, 1, &contador_dfs, &numero_filhos_raiz, pontes);
        auto ultima_ponte = pontes.end(); ultima_ponte--;
        for (auto itp = pontes.begin(); itp != pontes.end(); itp++) {
            if (itp != ultima_ponte)
                printf("%ld ", *itp);
            else
                printf("%ld\n", *itp);
        }
    }

    void Pontes::articulation_point_and_bridge (
        std::vector<std::vector<std::shared_ptr<Corredor> > >& lista_adjacencias,
        std::vector<int64_t> &dfs_low,
        std::vector<int64_t> &dfs_num,
        std::vector<int64_t> &dfs_parent,
        Tipos::vertice_t vertice, Tipos::vertice_t vertice_raiz, int* dfsNumberCounter, int* numero_filhos_raiz,
        std::set<Tipos::vertice_t>& pontes
    ) {

        dfs_low[vertice] = dfs_num[vertice] = (*dfsNumberCounter)++; // dfs_low[u] <= dfs_num[u]
        for (auto it = lista_adjacencias[vertice].begin(); it != lista_adjacencias[vertice].end(); it++) {
            auto vertice_vizinho = it->get()->num_vertice;
            if (it->get()->distancia == std::numeric_limits<Tipos::peso_t>::infinity())
                continue; // aresta nao faz parte da arvore de caminhos minimos
            if (dfs_num[vertice_vizinho] == -1) { // a tree edge
                dfs_parent[vertice_vizinho] = vertice; // parent of this children is me
                if (vertice == vertice_raiz) // special case
                    (*numero_filhos_raiz)++; // count children of root

                articulation_point_and_bridge (
                    lista_adjacencias, dfs_low, dfs_num, dfs_parent, 
                    vertice_vizinho, vertice_raiz, dfsNumberCounter, numero_filhos_raiz, pontes);

                dfs_low[vertice] = std::min(dfs_low[vertice], dfs_low[vertice_vizinho]); // update dfs_low[u]
                
            } else if ((int64_t)vertice_vizinho != dfs_parent[vertice]) // a back edge and not direct cycle
                dfs_low[vertice] = std::min(dfs_low[vertice], dfs_num[vertice_vizinho]); // update dfs_low[u]
        }
    }

    void Pontes::identifica_pontes_iterativo (
        std::vector<std::vector<std::shared_ptr<Corredor> > >& original,
        std::vector<std::vector<std::shared_ptr<Corredor> > >& lista_adjacencias,
        Tipos::vertice_t vertice_raiz
    ) {
        auto n = lista_adjacencias.size();
        std::vector<int64_t> dfs_low(n, -1);
        std::vector<int64_t> dfs_num(n, -1);
        std::vector<int64_t> dfs_parent(n, -1);
        std::vector<bool> visitados(n, false);
        std::vector<bool> em_fila(n, false);
        Tipos::vertice_t destino = (Tipos::vertice_t)(lista_adjacencias.size() - (unsigned long)1);
        int64_t dfs_contador = 0;

        std::stack<Tipos::vertice_t> Q;
        Q.push(vertice_raiz);
        em_fila[vertice_raiz] = true;

        while (!Q.empty()) {
            Tipos::vertice_t vertice = Q.top();
            Q.pop();
            dfs_low[vertice] = dfs_num[vertice] = dfs_contador;
            visitados[vertice] = true;
            em_fila[vertice] = false;

            for (auto it = lista_adjacencias[vertice].begin(); it != lista_adjacencias[vertice].end(); it++) {
                if (!visitados[it->get()->num_vertice] && !em_fila[it->get()->num_vertice])
                {
                    Q.push(it->get()->num_vertice);
                    em_fila[it->get()->num_vertice] = true;
                    dfs_parent[it->get()->num_vertice] = vertice;
                } else if (em_fila[it->get()->num_vertice]) {
                    dfs_parent[it->get()->num_vertice] = vertice;
                } else if (dfs_parent[vertice] != it->get()->num_vertice) {
                    if (dfs_low[it->get()->num_vertice] < dfs_low[vertice]) {
                        dfs_low[vertice] = dfs_low[it->get()->num_vertice];
                        Tipos::vertice_t aux = dfs_parent[vertice];
                        do {
                            if (dfs_low[it->get()->num_vertice] < dfs_low[aux])
                                dfs_low[aux] = dfs_low[it->get()->num_vertice];
                            aux = dfs_parent[aux];
                        } while (dfs_low[aux] != dfs_low[it->get()->num_vertice]);
                    }
                }
            }
            dfs_contador++;
        }

        Tipos::vertice_t vertice_atual = 1;

        for(auto it = original.begin() + 1; it != original.end(); it++) {
            for (auto iti = it->begin(); iti != it->end(); iti++) {
                if (iti->get()->distancia != std::numeric_limits<double>::infinity() && (dfs_low[iti->get()->num_vertice] > dfs_num[vertice_atual])) {
                    printf ("Ponte: %d\n", iti->get()->num_corredor);
                }
            }
            vertice_atual++;
        }
    }
}
