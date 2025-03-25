#include "bellman.h"

void BF(
        int graph[30][30],
        int numVertices,
        char startVertexChar,
        int *dist,
        int *prev
) {
    int startVertex = startVertexChar - 'A';

    dist[startVertex] = 0;

    int *dist1 = new int[numVertices];
    for (int i =0;i<numVertices;++i){
        dist1[i] = dist[i];
    }
    int *prev1 = new int[numVertices];
    for (int i =0;i<numVertices;++i){
        prev1[i] = prev[i];
    }
    for (int u = 0; u < numVertices; ++u) {
        if (u == startVertex) continue;
        int min = dist1[u];
        int previous = prev1[u];
        bool flag = 0;
        for (int v = 0; v < numVertices; ++v) {
            if (v == u) continue;
            if (graph[v][u]<= 0) continue;
            if (dist1[v] == -1 ) continue;


            if (dist1[v] + graph[v][u] < min || min == -1) {
                min = dist1[v] + graph[v][u];
                previous = v;
                flag = 1;
            }

            //cout<<min<<" "<<'\n';

        }
        if (flag){
            dist[u] = min;
            prev[u] = previous;
        }

    }

    delete []dist1;
    delete []prev1;

}

string BF_Path(
        int graph[30][30],
        int numVertices,
        char startVertex,
        char goalVertex
) {
    int BFValue[30];
    int BFPrev[30];

    for(int i=0;i<numVertices;i++){
        BFValue[i]=-1;
        BFPrev[i]=-1;
    }
    int storeStep[30][30];
    int storePrev[30][30];
    int m = 0;
    for (int i = 0; i<numVertices;++i){
        BF(graph,numVertices, startVertex,BFValue,BFPrev);
        for (int j = 0; j<numVertices;++j){
            storeStep[m][j] = BFValue[j];
            storePrev[m][j] = BFPrev[j];
        }
        m++;
    }
    string res="";
    char currChar = goalVertex;
    int step = numVertices - 1;
    while (currChar != startVertex){
        res = currChar + res;
        int prev1 = storePrev[step][currChar - 'A'];
        int temp = storePrev[step][currChar - 'A'];
        while (temp == prev1){
            step--;
            temp = storePrev[step][currChar - 'A'];
        }
        step++;
        currChar = storePrev[step][currChar - 'A'] + 'A' ;
    }
    res = currChar + res;
    string output;
    for (int i = 0; i < res.length(); ++i) {
        output += res[i];
        if (i != res.length() - 1) { // 
            output += ' ';
        }
    }
    return output;
}