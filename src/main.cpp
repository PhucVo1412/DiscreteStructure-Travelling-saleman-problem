#include <iostream>
#include "bellman.h"
#include "tsm.h"
#include "bellman.cpp"
#include "tsm.cpp"
using namespace std;
int main()
{
    int graph[30][30] = {
        {0, 12, 99, 75, 84, 77, 37, 65},
        {36, 0, 40, 90, 71, 38, 9, 75},
        {46, 72, 0, 38, 17, 46, 75, 8},
        {8, 57, 27, 0, 61, 88, 71, 7},
        {54, 60, 76, 66, 0, 24, 50, 15},
        {68, 54, 47, 70, 94, 0, 36, 40},
        {32, 11, 14, 44, 84, 18, 0, 61},
        {96, 59, 35, 4, 15, 63, 31, 0}
    };
    cout<<"This is our input graph: "<<endl;
    for (int i =0;i<8;i++){
        for (int j =0;j<8;++j){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    int BFValue[30];
    int BFPrev[30];
    int n=8;
    for(int i=0;i<n;i++){
        BFValue[i]=-1;
        BFPrev[i]=-1;
    }
           
    cout<<"Bellman-Ford test: "<<endl;
    for(int i=0;i<n;i++){
        BF(graph,n,'A',BFValue,BFPrev);
        cout<<"step"<<i+1<<":"<<endl;
        for(int j=0;j<n;j++){
            cout<<BFValue[j]<<" ";
        }
        cout<<endl;
        for(int j=0;j<n;j++){
            cout<<BFPrev[j]<<" ";
        }
        cout<<endl;
    }
    for (int i =1;i<8;i++){
        cout<<"Shortest path from A to "<< char(i+'A') <<": "<<BF_Path(graph,n,'A',char(i+'A'))<<endl;
    }




    int graph2[30][30]= {
        {0, 0, 0, 0, 50, 77, 49, 83, 24, 0, 0, 0},
        {66, 0, 0, 55, 58, 23, 79, 64, 0, 91, 0, 0},
        {26, 0, 0, 95, 0, 0, 67, 81, 0, 0, 9, 94},
        {0, 0, 0, 0, 22, 33, 77, 6, 76, 0, 5, 0},
        {46, 56, 0, 0, 0, 71, 55, 75, 24, 98, 77, 45},
        {77, 0, 48, 0, 0, 0, 0, 0, 33, 0, 0, 0},
        {4, 97, 74, 8, 21, 0, 0, 19, 70, 0, 0, 49},
        {89, 0, 19, 0, 51, 29, 0, 0, 20, 89, 41, 0},
        {81, 38, 0, 0, 9, 65, 0, 50, 0, 28, 0, 0},
        {27, 94, 9, 76, 0, 12, 0, 0, 0, 0, 47, 0},
        {42, 0, 78, 28, 0, 59, 0, 3, 0, 100, 0, 0},
        {17, 0, 74, 38, 60, 0, 17, 19, 0, 66, 0, 0}
    };
    
    cout<<"Traveling-saleman problem test: "<<endl;
    n = 12;
    cout<<"This is our input graph: "<<endl;
    for (int i =0;i<12;i++){
        for (int j =0;j<12;++j){
            cout<<graph2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Best solution path for this problem: "<<Traveling(graph2,n,'A');
    
    return 0;
}