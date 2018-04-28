#ifndef PONTES_H
#define PONTES_H

#include <vector>
#include <memory>

#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Util/Util.h"

using namespace Util;

namespace Algoritmos {
    struct Pontes {
        std::vector<std::shared_ptr<Corredor> > descobre_pontes (
            std::vector<std::vector<std::shared_ptr<Corredor> > >&,
            vertice_t, vertice_t, int=0
        );
    };
}

#endif