#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <limits>
#include <tuple>
#include <set>

#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Estruturas/Grafo/Grafo.h"
#include "Dijkstra.h"

using namespace std;

namespace Algoritmos {
    tuple<vector<Tipos::peso_t>, vector<Tipos::vertice_t> > Dijkstra::operator()(
        Tipos::vertice_t origem,
        const Tipos::Grafo_t &lista_adjacencia)
    {
        unsigned long tam_lista_adjacencia = lista_adjacencia.size();

        vector<Tipos::peso_t> distancia_minima(tam_lista_adjacencia, numeric_limits<Tipos::peso_t>::infinity());
        vector<Tipos::vertice_t> predecessores(tam_lista_adjacencia, -1);
        set<pair<Tipos::peso_t, Tipos::vertice_t> > fila_vertices;
        
        distancia_minima[origem] = 0;
        fila_vertices.insert(make_pair(distancia_minima[origem], origem));
    
        while (!fila_vertices.empty()) 
        {
            Tipos::peso_t dist = fila_vertices.begin()->first;
            Tipos::vertice_t num_vizinho = fila_vertices.begin()->second;
            fila_vertices.erase(fila_vertices.begin());
    
            for (auto &&corredor_it : lista_adjacencia[num_vizinho]) {
                auto corredor = *corredor_it.get();
                Tipos::vertice_t vertice = corredor.num_vertice;
                Tipos::peso_t peso = corredor.distancia;
                Tipos::peso_t distance_through_u = dist + peso;
                if (distance_through_u < distancia_minima[vertice]) {
                    fila_vertices.erase(make_pair(distancia_minima[vertice], vertice));
                    distancia_minima[vertice] = distance_through_u;
                    predecessores[vertice] = num_vizinho;
                    fila_vertices.insert(make_pair(distancia_minima[vertice], vertice));
                }
            }
        }
        return make_tuple(distancia_minima, predecessores);
    }
}
