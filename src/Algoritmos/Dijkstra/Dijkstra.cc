#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <limits>
#include <tuple>
#include <set>

#include "Dijkstra.h"
#include "../../Estruturas/Corredor/Corredor.h"

namespace Algoritmos {
    std::tuple<std::vector<Tipos::peso_t>, std::vector<Tipos::vertice_t> > Dijkstra::operator()(
        Tipos::vertice_t origem,
        const std::vector<std::vector<std::shared_ptr<Corredor> > > &lista_adjacencia)
    {
        unsigned long tam_lista_adjacencia = lista_adjacencia.size();

        std::vector<Tipos::peso_t> distancia_minima(tam_lista_adjacencia, std::numeric_limits<Tipos::peso_t>::infinity());
        std::vector<Tipos::vertice_t> predecessores(tam_lista_adjacencia, -1);
        std::set<std::pair<Tipos::peso_t, Tipos::vertice_t> > fila_vertices;
        
        distancia_minima[origem] = 0;
        fila_vertices.insert(std::make_pair(distancia_minima[origem], origem));
    
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
                    fila_vertices.erase(std::make_pair(distancia_minima[vertice], vertice));
                    distancia_minima[vertice] = distance_through_u;
                    predecessores[vertice] = num_vizinho;
                    fila_vertices.insert(std::make_pair(distancia_minima[vertice], vertice));
                }
            }
        }
        return std::make_tuple(distancia_minima, predecessores);
    }

    void Dijkstra::imprime_caminho_minimo (
        FILE *arq_saida,
        std::tuple<std::vector<Tipos::peso_t>, std::vector<Tipos::vertice_t> > &tupla_caminho,
        Tipos::vertice_t vertice) {
        auto predecessores = std::get<1>(tupla_caminho);
        if (vertice == -1) return;
        imprime_caminho_minimo(arq_saida, tupla_caminho, (Tipos::vertice_t)predecessores[vertice]);
        // auto pesos = std::get<0>(tupla_caminho);
        if (vertice != (Tipos::vertice_t)predecessores.size())
            fprintf(arq_saida, "%ld - ", vertice);
        else 
            fprintf(arq_saida, "%ld\n", vertice);
        return;
        // while (vertice != -1) {
        //     std::cout << vertice << " - ";
        //     vertice = predecessores[vertice];
        // }
    }
}
