camadas = 2
custo = 10**6
num_vertices = 8
num_vert_camada = (num_vertices - 2)/camadas
num_arestas = num_vert_camada * camadas + 2.0 * num_vert_camada

print("%d %d"%(num_vertices, num_arestas))

for vertice in range(1, num_vert_camada + 1):
    print("%d %d %d"%(1, vertice + 1, custo))

for camada in range(1, camadas):
    for vertice in range(1, num_vert_camada + 1):
        vertice_camada_atual = (camada-1) * num_vert_camada + (vertice + 1)
        for k in range(1, num_vert_camada + 1):
            vertice_camada_seguinte = camada * num_vert_camada + (k + 1)
            print("%d %d %d" %(vertice_camada_atual, vertice_camada_seguinte, custo))

for vertice in range(1 + (camadas - 1) * num_vert_camada + 1, 1 + camadas * num_vert_camada + 1):
    print ("%d %d %d" %(vertice, num_vertices, custo))

