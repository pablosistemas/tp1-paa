#include <iostream>
#include <memory>

#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Estruturas/Grafo/Grafo.h"
#include "../../Util/Tipos.h"
#include "Dfs.h"

using namespace std;

namespace Algoritmos {
    void Dfs::operator() (
        const Tipos::Grafo_t& lista_adjacencias,
        Tipos::vertice_t origem, Tipos::vertice_t destino, vector<Tipos::peso_t> &distancias_minimas
    )
    {
        unsigned long n = lista_adjacencias.size();
        vector<bool> visitados(n+1, false);
        vector<Tipos::vertice_t > Q;
        Q.push_back(origem);
        visitados[origem] = true;
        
        if(origem == destino) return;
        cout << " Depth first Search starting from vertex ";
        cout << origem << " : " << endl;

        while(!Q.empty())
        {
            Tipos::vertice_t k = Q.front();
            Q.erase(Q.begin());
            cout << k << " ";
            
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
        cout << endl;
    }
}
