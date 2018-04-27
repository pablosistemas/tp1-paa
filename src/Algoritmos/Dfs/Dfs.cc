#include <iostream>
#include <memory>

#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Util/Util.h"
#include "Dfs.h"

using namespace Util;

namespace Algoritmos {
    // depth-first method
    // SL : state list (current path being tried)
    // NSL: new state list (nodes awaiting evaluation)
    // DE : dead ends, state whose descendants have failed to contain a
    // goal node
    // CS : current state
    void Dfs::operator() (
        const std::vector<std::vector<std::shared_ptr<Corredor> > > &lista_adjacencias,
        vertice_t origem, vertice_t destino, std::vector<peso_t> &distancias_minimas
    )
    {
        unsigned long n = lista_adjacencias.size();
        std::vector<bool> visitados(n+1, false);
        std::vector<vertice_t > Q;
        Q.push_back(origem);
        visitados[origem] = true;
        
        if(origem == destino) return;
        std::cout << " Depth first Search starting from vertex ";
        std::cout << origem << " : " << std::endl;

        while(!Q.empty())
        {
            vertice_t k = Q.front();
            Q.erase(Q.begin());
            std::cout << k << " ";
            
            if(k == destino) {
                break;
            }
            
            for (auto it = lista_adjacencias[k].begin(); it != lista_adjacencias[k].end(); it++)
                if (!visitados[it->get()->num_vertice])
                {
                    Q.push_back(it->get()->num_vertice);
                    visitados[it->get()->num_vertice] = true;
                }
        }
        std::cout << std::endl;
    }
}