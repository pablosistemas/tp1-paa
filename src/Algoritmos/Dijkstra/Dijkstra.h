#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <tuple>

#include "../../Util/Util.h"
#include "../../Estruturas/Corredor/Corredor.h"

using namespace Util;

namespace Algoritmos {
    struct Dijkstra {
        std::tuple<std::vector<peso_t>, std::vector<vertice_t> >  operator()(
            vertice_t,
            const std::vector<std::vector<std::shared_ptr<Corredor> > > &
        );

        static void imprime_caminho_minimo(
            FILE*,
            std::tuple<std::vector<peso_t>, std::vector<vertice_t> > &,
            vertice_t);
    };
}

#endif