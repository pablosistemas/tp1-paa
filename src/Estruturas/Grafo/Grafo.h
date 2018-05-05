#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <memory>
#include "../Corredor/Corredor.h"
#include "../../Util/Tipos.h"

using namespace std;

namespace Tipos {
    typedef vector<vector<shared_ptr<Corredor> > > Grafo_t;
}

struct Grafo {
    static Tipos::Grafo_t calcula_grafo_transposto(
        Tipos::Grafo_t&);
    
    static Tipos::Grafo_t determina_todas_arestas_caminho_minimo (
        FILE *,        
        Tipos::Grafo_t&,
        vector<Tipos::peso_t>&,
        vector<Tipos::peso_t>&);
};


#endif
