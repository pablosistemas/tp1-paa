#include <memory>

#include "../Corredor/Corredor.h"
#include "../../Util/Util.h"
#include "Grafo.h"

std::vector<std::vector<std::shared_ptr<Corredor> > > Grafo::calcula_grafo_transposto(
    std::vector<std::vector<std::shared_ptr<Corredor> > >&lista_adjacencias) {
    
    std::function<void(Corredor *)> destrutor_corredor = [](Corredor *p) {
        delete p;
    };

    std::vector<std::vector<std::shared_ptr<Corredor> > > transposto(lista_adjacencias.size());
    auto idx = 0;
    for (auto it = lista_adjacencias.begin(); it != lista_adjacencias.end(); it++) {
        for (auto itv = it->begin(); itv != it->end(); itv++) {
            std::shared_ptr<Corredor> s_c (
                new Corredor(itv->get()->num_corredor, idx, itv->get()->distancia),
                destrutor_corredor);
            transposto[itv->get()->num_vertice].push_back(s_c);
        }
        idx++;
    }
    return transposto;
}
