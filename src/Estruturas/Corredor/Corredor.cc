#include "Corredor.h"
#include "../../Util/Tipos.h"

Corredor::Corredor(uint64_t num_c, uint64_t num_v, double dist) {
    num_corredor = num_c;
    num_vertice = num_v;
    distancia = dist;
}