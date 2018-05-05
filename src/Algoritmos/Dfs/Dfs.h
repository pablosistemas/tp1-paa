#ifndef DFS_H
#define DFS_H

#include <vector>
#include <memory>
#include "../../Estruturas/Corredor/Corredor.h"
#include "../../Util/Tipos.h"

using namespace std;

namespace Algoritmos {
    struct Dfs {
        void operator() (
            const vector<vector<shared_ptr<Corredor> > > &,
            Tipos::vertice_t, Tipos::vertice_t, vector<Tipos::peso_t> &
        );
    };
}

#endif