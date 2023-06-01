#include <iostream>
#include <limits.h>
using namespace std;

int minPath(int dist[], bool prev[]){
    int min = INT_MAX;
    int minLabel;
    for (int v=0;v<6;v++){
        if (prev[v]==false and dist[v]<=min){
            min = dist[v];
            minLabel = v;
        }
    }
    return minLabel;
}

void print(int dist[],int v){
    float avg,total;
    cout<<"city"<<"\t"<<"distance from source"<<endl;
    for (int i=0;i<v;i++){
        total += dist[i];
        cout<<i<<"\t"<<"\t"<<dist[i]<<endl;
    }
    avg = total/5;
    cout<<"average cost = "<<avg<<endl;
    cout<<""<<endl;
}

void dijkstra(int graph[6][6],int src){
    int dist[6];
    bool prev[6];
    for (int i=0;i<6;i++){
        dist[i] = INT_MAX;
        prev[i]  = false;
    }
    dist[src] = 0;
    for (int j=0;j<6;j++){
        int u = minPath(dist,prev);
        prev[u] = true;
        for (int v=0;v<6;v++){
            if ((!prev[v] and graph[u][v] and dist[u] != INT_MAX) and dist[v]>dist[u]+graph[u][v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    print(dist,6);
}

int main() {
    int graph[6][6] = {{0,10,0,0,15,5},
    {10,0,10,30,0,0},
    {0,10,0,12,5,0},
    {0,30,12,0,0,20},
    {15,0,5,0,0,0},
    {5,0,0,20,0,0}};
    for (int l=0;l<6;l++){
        dijkstra(graph,l);
    }
}