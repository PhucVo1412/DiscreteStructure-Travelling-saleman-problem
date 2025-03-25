#include "tsm.h"

const int MAX = 10000000;
int** f;
int** parent;

int tsp(int graph[30][30], int numVertices, int v, int mask, char startVertex) {
    if (mask == (1 << numVertices) - 1)
        return graph[v][startVertex - 'A'] == 0 ? MAX : graph[v][startVertex - 'A'];

    if (f[v][mask] != -1)
        return f[v][mask];

    int res = MAX;
    for (int u = 0; u < numVertices; u++) {
        if (!(mask & (1 << u)) && graph[v][u] != 0) {
            int newCost = graph[v][u] + tsp(graph, numVertices, u, mask | (1 << u), startVertex);
            if (newCost < res) {
                res = newCost;
                parent[v][mask] = u;
            }
        }
    }

    return f[v][mask] = res;
}

string getPath(int numVertices, char startVertex) {
    string path = "";
    int current = startVertex - 'A';
    int mask = 1 << current;
    while (true) {
        path += (char)(current + 'A');
        path += " ";
        int next = parent[current][mask];
        if (next == -1)
            break;
        mask |= (1 << next);
        current = next;
    }

    path += startVertex;
    return path;
}


string Traveling(int graph[30][30], int numVertices, char startVertex) {
    f = new int*[numVertices];
    parent = new int*[numVertices];

    for (int i = 0; i < numVertices; i++) {
        f[i] = new int[1 << numVertices];
        parent[i] = new int[1 << numVertices];

        for (int j = 0; j < (1 << numVertices); j++) {
            f[i][j] = -1;
            parent[i][j] = -1;
        }
    }

    int minCost = tsp(graph, numVertices, startVertex - 'A', 1 <<(startVertex - 'A'), startVertex);

    if (minCost >= MAX) {
        cout << "No feasible solution exists." << endl;
        return "";
    }


    string result = getPath(numVertices, startVertex);
    return result;
}


