#ifndef PONTES_H
#define PONTES_H

#include <vector>
#include <memory>
#include <set>

#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Util/Tipos.h"

namespace Algoritmos {
    struct Pontes {
        static void calcula_pontes (std::vector<std::vector<std::shared_ptr<Corredor> > >&);

        static void articulation_point_and_bridge (
            std::vector<std::vector<std::shared_ptr<Corredor> > >&,
            std::vector<int64_t> &,
            std::vector<int64_t> &,
            std::vector<int64_t> &,
            Tipos::vertice_t, Tipos::vertice_t, int* , int*, std::set<Tipos::vertice_t>&);
        
        static void identifica_pontes_iterativo (
            std::vector<std::vector<std::shared_ptr<Corredor> > >&,
            std::vector<std::vector<std::shared_ptr<Corredor> > >&,
            Tipos::vertice_t);
    };
}

#endif
