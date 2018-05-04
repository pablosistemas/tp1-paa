camadas = 1
custo = 10**6
num_vertices_total = 10**4
num_vertices_espinha = num_vertices_total/2
num_vert_camada = (num_vertices_espinha - 2)/camadas

if camadas == 1:
    num_arestas = 2 * (2 * num_vert_camada) + 1
else:
    num_arestas = 2 * (num_vert_camada * camadas + 2.0 * num_vert_camada)

print("%d %d"%(num_vertices_total, num_arestas))

for start_range in [1, num_vertices_espinha + 1]:

    for vertice in range(1, num_vert_camada + 1):
        print("%d %d %d"%(start_range, start_range + vertice, custo))

    for camada in range(1, camadas):
        for vertice in range(1, num_vert_camada + 1):
            vertice_camada_atual = (camada-1) * num_vert_camada + (vertice + start_range)
            for k in range(1, num_vert_camada + 1):
                vertice_camada_seguinte = camada * num_vert_camada + (k + start_range)
                print("%d %d %d" %(vertice_camada_atual, vertice_camada_seguinte, custo))

    for vertice in range(start_range + (camadas - 1) * num_vert_camada + 1, start_range + camadas * num_vert_camada + 1):
        print ("%d %d %d" %(vertice, num_vertices_espinha, custo))
    
    if start_range == 1:
        print("%d %d %d"%(num_vertices_espinha, num_vertices_espinha + 1, custo))

    num_vertices_espinha *= 2

