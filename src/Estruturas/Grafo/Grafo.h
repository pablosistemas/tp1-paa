#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <memory>
#include "../Corredor/Corredor.h"
#include "../../Util/Tipos.h"

struct Grafo {
    static std::vector<std::vector<std::shared_ptr<Corredor> > > calcula_grafo_transposto(
        std::vector<std::vector<std::shared_ptr<Corredor> > >&);
    
    static std::vector<std::vector<std::shared_ptr<Corredor> > > determina_todas_arestas_caminho_minimo (
        std::vector<std::vector<std::shared_ptr<Corredor> > >&,
        std::vector<Tipos::peso_t>&,
        std::vector<Tipos::peso_t>&);
};

#endif
