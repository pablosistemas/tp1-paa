#ifndef CORREDOR_H
#define CORREDOR_H

#include <cinttypes>

struct Corredor {
    int num_corredor;
    int num_vertice;
    int64_t distancia;
    int cor;

    Corredor(int, int, int64_t);
};

#endif