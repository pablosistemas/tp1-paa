#include <iterator>
#include <memory>
#include <limits>
#include <set>

#include "../Corredor/Corredor.h"
#include "../../Util/Tipos.h"
#include "Grafo.h"

using namespace std;

vector<vector<shared_ptr<Corredor> > > Grafo::calcula_grafo_transposto (
    Tipos::Grafo_t& lista_adjacencias) {
    
    function<void(Corredor *)> destrutor_corredor = [](Corredor *p) {
        delete p;
    };

    vector<vector<shared_ptr<Corredor> > > transposto(lista_adjacencias.size());
    uint64_t idx = 1;
    for (auto it = lista_adjacencias.begin() + 1; it != lista_adjacencias.end(); it++) {
        for (auto itv = it->begin(); itv != it->end(); itv++) {
            shared_ptr<Corredor> s_c (
                new Corredor(itv->get()->num_corredor, idx, itv->get()->distancia), destrutor_corredor);
            transposto[itv->get()->num_vertice].push_back(s_c);
        }
        idx++;
    }
    return transposto;
}

vector<vector<shared_ptr<Corredor> > > Grafo::determina_todas_arestas_caminho_minimo (
    FILE *arq_saida,
    Tipos::Grafo_t& lista_adjacencias,
    vector<Tipos::peso_t>& pesos_original,
    vector<Tipos::peso_t>& pesos_transposto) {
    
    function<void(Corredor *)> destrutor_corredor = [](Corredor *p) {
        delete p;
    };

    vector<bool> visitado (lista_adjacencias.size(), false);
    vector<vector<shared_ptr<Corredor> > > lista_adj_nao_direcionada(lista_adjacencias.size());

    set<Tipos::vertice_t> arestas_pertencem_caminho_minimo;

    Tipos::vertice_t vertice_atual = 1;
    for (auto it = lista_adjacencias.begin() + 1; it != lista_adjacencias.end(); it++) {
        for (auto iti = it->begin(); iti != it->end(); iti++) {
            auto peso_caminho_atual = 
                pesos_original[vertice_atual] + 
                iti->get()->distancia +
                pesos_transposto[iti->get()->num_vertice];

            if (peso_caminho_atual != pesos_original[pesos_original.size() - 1]) {
                iti->get()->distancia = numeric_limits<double>::infinity();
            } else {
                if (visitado[iti->get()->num_vertice] == false) {
                    shared_ptr<Corredor> s_c (
                        new Corredor(iti->get()->num_corredor, vertice_atual, iti->get()->distancia), destrutor_corredor);
                    lista_adj_nao_direcionada[iti->get()->num_vertice].push_back(s_c);
                }
                arestas_pertencem_caminho_minimo.insert(iti->get()->num_corredor);
                lista_adj_nao_direcionada[vertice_atual].push_back(*iti);
            }
        }
        visitado[vertice_atual] = true;
        vertice_atual++;
    }

    fprintf (arq_saida, "%lu\n", arestas_pertencem_caminho_minimo.size());
    auto last_it = arestas_pertencem_caminho_minimo.end();
    if (arestas_pertencem_caminho_minimo.size() > 0) {
        advance(last_it, -1);
        for (auto ita = arestas_pertencem_caminho_minimo.begin(); ita != last_it; ita++) {
            fprintf (arq_saida, "%ld ", *ita);
        }
        fprintf (arq_saida, "%ld", *last_it);
    }
    fprintf (arq_saida, "\n");
    return lista_adj_nao_direcionada;
}
