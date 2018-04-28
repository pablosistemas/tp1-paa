#ifndef UTIL_H
#define UTIL_H

#include <functional>
#include "../Estruturas/Corredor/Corredor.h"

namespace Util {

    typedef int vertice_t;
    typedef double peso_t;

    static int DFS_WHITE = -1;
    static int DFS_BLACK = 1;
    static int DFS_GRAY = 0;
}

#endif