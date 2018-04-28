#include <algorithm>
#include <vector>
#include <memory>

#include "Pontes.h"
#include "../../Util/Util.h"
#include "../../Estruturas/Corredor/Corredor.h"

using namespace Util;

namespace Algoritmos {
    struct Pontes {

        void calcula_pontes (
            std::vector<std::vector<std::shared_ptr<Corredor> > >& lista_adjacencias
        ) {
            auto n = lista_adjacencias.size();
            std::vector<int> dfs_low(n, DFS_WHITE);
            std::vector<int> dfs_num(n, DFS_WHITE);
            std::vector<int> dfs_parent(n, DFS_WHITE);
            std::vector<int> vertice_articulacao (n, DFS_WHITE);
            int numero_filhos_raiz = 0;

            auto pontes = articulation_point_and_bridge (
                lista_adjacencias, dfs_low, dfs_num, dfs_parent, 1, 1, 0, &numero_filhos_raiz);
        }

        std::vector<std::shared_ptr<Corredor> > articulation_point_and_bridge (
            std::vector<std::vector<std::shared_ptr<Corredor> > >& lista_adjacencias,
            std::vector<int> &dfs_low,
            std::vector<int> &dfs_num,
            std::vector<int> &dfs_parent,
            vertice_t vertice, vertice_t vertice_raiz, int dfsNumberCounter, int* numero_filhos_raiz
        ) {

            dfs_low[vertice] = dfs_num[vertice] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
            for (auto it = lista_adjacencias[vertice].begin(); it != lista_adjacencias[vertice].end(); it++) {
                auto vertice_vizinho = it->get()->num_vertice;
                if (dfs_num[vertice_vizinho] == DFS_WHITE) { // a tree edge
                    dfs_parent[vertice_vizinho] = vertice; // parent of this children is me
                    if (vertice == vertice_raiz) // special case
                        (*numero_filhos_raiz)++; // count children of root

                    articulation_point_and_bridge (
                        lista_adjacencias, dfs_low, dfs_num, dfs_parent, 
                        vertice_vizinho, vertice_raiz, dfsNumberCounter, numero_filhos_raiz);

                    if (dfs_low[vertice_vizinho] > dfs_num[vertice]) // for bridge
                        printf(" Edge (%d, %d) is a bridge\n", vertice, vertice_vizinho);

                    dfs_low[vertice] = std::min(dfs_low[vertice], dfs_low[vertice_vizinho]); // update dfs_low[u]
                }
                else if (vertice_vizinho != dfs_parent[vertice]) // a back edge and not direct cycle
                    dfs_low[vertice] = std::min(dfs_low[vertice], dfs_num[vertice_vizinho]); // update dfs_low[u]
            }
        }
    };
}
