#include <functional>
#include <cinttypes>
#include <iostream>
#include <cstring>
#include <memory>
#include <vector>
#include <cstdio>
#include <cerrno>
#include <tuple>

#include "../Estruturas/Corredor/Corredor.h"
#include "../Algoritmos/Dijkstra/Dijkstra.h"
#include "../Algoritmos/Pontes/Pontes.h"
#include "../Estruturas/Grafo/Grafo.h"
#include "../Algoritmos/Dfs/Dfs.h"
#include "../Util/Tipos.h"

using namespace Algoritmos;
using namespace std;

int main(int argc, char **argv) {
    if (argc < 2) { return -1; }

    unsigned long num_locais_proibidos, num_corredores_permitidos;
    vector<vector<shared_ptr<Corredor> > > corredores_adjacentes;

    function<void(Corredor *)> destrutor_corredor = [](Corredor *p) {
        delete p;
    };

    FILE *arq_entrada = fopen(argv[1], "r");
    if (arq_entrada == NULL) {
        cout << strerror(errno) << endl;
        return -1;
    }

    FILE *arq_saida = fopen(argv[2], "w+");
    if (arq_saida == NULL) {
        cout << strerror(errno) << endl;
        fclose(arq_entrada);
        return -1;
    }

    fscanf(arq_entrada, "%lu %lu\n", &num_locais_proibidos, &num_corredores_permitidos);
    
    corredores_adjacentes.resize(num_locais_proibidos + 1); // 1 - N

    int64_t dist_a_b;
    int local_a, local_b;

    for (unsigned long M = 1; M <= num_corredores_permitidos; M++) {
        fscanf(arq_entrada, "%d %d %ld\n", &local_a, &local_b, &dist_a_b);
        shared_ptr<Corredor> s_c (new Corredor(M, local_b, dist_a_b), destrutor_corredor);
        corredores_adjacentes[local_a].push_back(s_c);
    }

    auto tupla_caminho_minimo = Dijkstra()(1, corredores_adjacentes);

    auto caminhos = get<0>(tupla_caminho_minimo);
    auto pesos_minimo = get<1>(tupla_caminho_minimo);

    auto transposto = Grafo::calcula_grafo_transposto(corredores_adjacentes);
    auto tupla_caminho_minimo_transposto = Dijkstra()(transposto.size() - 1, transposto);

    auto lista_adj_nao_direcionada = Grafo::determina_todas_arestas_caminho_minimo (
        arq_saida,
        corredores_adjacentes,
        get<0>(tupla_caminho_minimo),
        get<0>(tupla_caminho_minimo_transposto));
    
    Pontes::identifica_pontes_iterativo (arq_saida, corredores_adjacentes, lista_adj_nao_direcionada, 1);

    fclose(arq_entrada);
    fclose(arq_saida);

    return 0;
}
