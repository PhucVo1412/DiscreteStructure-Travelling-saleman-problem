#include <iostream>
using namespace std;
int tsp(int graph[30][30], int numVertices, int current, int mask, char startVertex);
string getPath(int numVertices, char startVertex);
string Traveling(int graph[30][30], int numVertices, char startVertex);