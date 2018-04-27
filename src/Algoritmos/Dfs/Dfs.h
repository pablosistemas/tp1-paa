#ifndef DFS_H
#define DFS_H

#include <vector>
#include <memory>
#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Util/Util.h"

using namespace Util;

namespace Algoritmos {
    struct Dfs {
        void operator() (
            const std::vector<std::vector<std::shared_ptr<Corredor> > > &,
            vertice_t, vertice_t, std::vector<peso_t> &
        );
    };
}

#endif