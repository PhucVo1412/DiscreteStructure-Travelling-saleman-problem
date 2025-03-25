#include <iostream>

using namespace std;

void BF(
        int graph[30][30],
        int numVertices,
        char startVertexChar,
        int *dist,
        int *prev
);

string BF_Path(
        int graph[30][30],
        int numVertices,
        char startVertex,
        char goalVertex
);