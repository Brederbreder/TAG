Compilar o programa usando as seguintes linhas de comando
g++ -std=c++11 -c grafo.cpp
g++ -st=c++11 -o exec main.cpp grafo.o
./exec

e para gerar a imagem do grafo utilizar a seguinte linha de comando
dot -Tpng grafo.dot -o grafo.png

(o caminho critico nao conta com o peso do ultimo vertice, apenas a soma dos pesos dos vertices ate chegar no ultimo vertice)
