#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <tuple>

#include "../../Util/Tipos.h"
#include "../../Estruturas/Corredor/Corredor.h"

namespace Algoritmos {
    struct Dijkstra {
        std::tuple<std::vector<Tipos::peso_t>, std::vector<Tipos::vertice_t> >  operator()(
            Tipos::vertice_t,
            const std::vector<std::vector<std::shared_ptr<Corredor> > > &
        );

        static void imprime_caminho_minimo(
            FILE*,
            std::tuple<std::vector<Tipos::peso_t>, std::vector<Tipos::vertice_t> > &,
            Tipos::vertice_t);
    };
}

#endif