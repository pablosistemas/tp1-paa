#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <tuple>

#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Estruturas/Grafo/Grafo.h"
#include "../../Util/Tipos.h"

using namespace std;

namespace Algoritmos {
    struct Dijkstra {
        tuple<vector<Tipos::peso_t>, vector<Tipos::vertice_t> >  operator()(
            Tipos::vertice_t,
            const Tipos::Grafo_t &
        );
    };
}

#endif