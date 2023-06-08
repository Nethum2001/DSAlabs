#include <iostream>
using namespace std;

int extractMin(int key[],bool visited[]){
    int min = INT_MAX;
    int minLabel;
    for (int v=0;v<6;v++){
        if (visited[v]==false and key[v]<=min){
            min = key[v];
            minLabel = v;
        }
    }
    return minLabel;
}

void print(int path[],int graph[6][6]){
    cout<<"edge \tweight"<<endl;
    for (int i=1;i<6;i++){
        cout<<path[i]<<" - "<<i<<"\t"<<graph[i][path[i]]<<endl;
    }
}

void prim(int graph[6][6]){
    int path[6];
    int key[6];
    bool visited[6];
    for (int i=0;i<6;i++){
        key[i] = INT_MAX;
        visited[i] = false;
    }
    key[0] = 0;
    path[0] = 0;
    for (int j=0;j<5;j++){
        int u = extractMin(key,visited);
        visited[u] = true;
        for (int v=0;v<6;v++){
            if (graph[u][v] && visited[v]==false && graph[u][v]<key[v]){
                path[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    print(path,graph);
}

int main() {
    int graph[6][6] = {{0,3,0,0,0,1},
    {3,0,2,1,10,0},
    {0,2,0,3,0,5},
    {0,1,3,0,5,0},
    {0,10,0,5,0,4},
    {1,0,5,0,4,0}};
    prim(graph);
}