#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <limits>
#include <tuple>
#include <set>

#include "Dijkstra.h"
#include "../../Estruturas/Corredor/Corredor.h"

using namespace Util;

namespace Algoritmos {
    std::tuple<std::vector<peso_t>, std::vector<vertice_t> > Dijkstra::operator()(vertice_t origem,
                          const std::vector<std::vector<std::shared_ptr<Corredor> > > &lista_adjacencia)
    {
        std::vector<peso_t> distancia_minima;
        unsigned long tam_lista_adjacencia = lista_adjacencia.size();
        distancia_minima.resize(tam_lista_adjacencia, std::numeric_limits<peso_t>::infinity());
        distancia_minima[origem] = 0;
        std::vector<vertice_t> predecessores(tam_lista_adjacencia, -1);
        std::set<std::pair<peso_t, vertice_t> > fila_vertices;
        fila_vertices.insert(std::make_pair(distancia_minima[origem], origem));
    
        while (!fila_vertices.empty()) 
        {
            peso_t dist = fila_vertices.begin()->first;
            vertice_t num_vizinho = fila_vertices.begin()->second;
            fila_vertices.erase(fila_vertices.begin());
    
            const std::vector<std::shared_ptr<Corredor> > &corredores = lista_adjacencia[num_vizinho];
            for (auto &&corredor_it : corredores) {
                auto corredor = *corredor_it;
                vertice_t vertice = corredor.num_vertice;
                peso_t peso = corredor.distancia;
                peso_t distance_through_u = dist + peso;
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
        std::tuple<std::vector<peso_t>, std::vector<vertice_t> > &tupla_caminho,
        vertice_t vertice) {
        auto predecessores = std::get<1>(tupla_caminho);
        if (vertice == -1) return;
        imprime_caminho_minimo(arq_saida, tupla_caminho, (vertice_t)predecessores[vertice]);
        // auto pesos = std::get<0>(tupla_caminho);
        if (vertice != (vertice_t)predecessores.size())
            fprintf(arq_saida, "%d - ", vertice);
        else 
            fprintf(arq_saida, "%d\n", vertice);
        return;
        // while (vertice != -1) {
        //     std::cout << vertice << " - ";
        //     vertice = predecessores[vertice];
        // }
    }
}
