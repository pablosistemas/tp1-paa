#ifndef PONTES_H
#define PONTES_H

#include <vector>
#include <memory>
#include <set>

#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Util/Tipos.h"

using namespace std;

namespace Algoritmos {
    struct Pontes {
        static void calcula_pontes (vector<vector<shared_ptr<Corredor> > >&);

        static void articulation_point_and_bridge (
            vector<vector<shared_ptr<Corredor> > >&,
            vector<int64_t> &,
            vector<int64_t> &,
            vector<int64_t> &,
            Tipos::vertice_t, Tipos::vertice_t, int* , int*, set<Tipos::vertice_t>&);
        
        static void identifica_pontes_iterativo (
            FILE *,
            vector<vector<shared_ptr<Corredor> > >&,
            vector<vector<shared_ptr<Corredor> > >&,
            Tipos::vertice_t);
    };
}

#endif
