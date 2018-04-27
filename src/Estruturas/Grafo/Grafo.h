#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <memory>
#include "../Corredor/Corredor.h"

struct Grafo {
    static std::vector<std::vector<std::shared_ptr<Corredor> > > calcula_grafo_transposto(
        std::vector<std::vector<std::shared_ptr<Corredor> > >&);
};

#endif