#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
  public:
    int V,E;
    int **adjM;
    Graph(int n)
    {
        V=n;
        E=0;
        adjM=new int*[n];
        for(int i=0;i<V;i++)
            adjM[i]=new int[n];
    }
};

void addEdge(Graph *g,int i,int j)
{
    if(i>=g->V|| j>=g->V)
        return;
    if(g->adjM[i][j]==0)
    {
        g->adjM[i][j]=1;
        (g->E)++;
    }
}

void displayEdges(Graph *g)
{
    cout<<"Edges are"<<endl;
    for(int i=0;i<g->V;i++)
    {
        for(int j=0;j<g->V;j++)
        {
            if(g->adjM[i][j]==1)
                cout<<i<<"->"<<j<<endl;
        }
    }
}

void print(Graph *g)
{
    cout<<"Contents of Graph are:"<<endl;
    for(int i=0;i<g->V;i++)
    {
        for(int j=0;j<g->V;j++)
            cout<<g->adjM[i][j]<<" ";
        cout<<endl;
    }
}

void distroyGraph(Graph *g)
{
    if(g)
    {
        if(g->adjM)
        {
            for(int i=0;i<g->V;i++)
                delete(g->adjM[i]);
            delete(g->adjM);
        }
    }
    cout<<"Graph distroyed"<<endl;
}

int main()
{
    int n=4;
    Graph *g=new Graph(n);  
    addEdge(g,0,1);
    addEdge(g,0,3);
    addEdge(g,2,1);
    addEdge(g,2,3);
    addEdge(g,2,0);
    print(g);
    displayEdges(g);
    distroyGraph(g);
    return 0;
}

