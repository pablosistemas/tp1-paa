#ifndef DFS_H
#define DFS_H

#include <vector>
#include <memory>
#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Util/Tipos.h"

namespace Algoritmos {
    struct Dfs {
        void operator() (
            const std::vector<std::vector<std::shared_ptr<Corredor> > > &,
            Tipos::vertice_t, Tipos::vertice_t, std::vector<Tipos::peso_t> &
        );
    };
}

#endif