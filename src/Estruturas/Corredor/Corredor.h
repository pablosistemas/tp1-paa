#ifndef CORREDOR_H
#define CORREDOR_H

#include <cinttypes>
#include "../../Util/Tipos.h"

struct Corredor {
    uint64_t num_corredor;
    uint64_t num_vertice;
    double distancia;

    Corredor(uint64_t, uint64_t, double);
};

#endif