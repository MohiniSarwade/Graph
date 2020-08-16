#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adjL;   
  public:
    Graph(int n)
    {
        V=n;
        adjL=new list<int>[V];
    }
    void addEdge(int u, int w);
    void DFS(bool vistied[],int start);
};

void Graph::addEdge(int u, int w)
{
    adjL[u].push_back(w);
}

void Graph::DFS(bool visited[],int i)
{
    visited[i]=true;
    cout<<i<<" ";
    
    list<int>::iterator it;
    for(auto it=adjL[i].begin();it!=adjL[i].end();++it)
    {
        if(!visited[*it])
            DFS(visited,*it);
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 3); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(2, 1); 
    
    bool *visited=new bool[4];
    for(int i=0;i<4;i++)
        visited[i]=false;
    int count =0;
    
    cout<<"DFS traversal of graph is "<<endl;
    for(int i=0;i<4;i++)
    {
        if(visited[i]==false)
        {
            count++;
            g.DFS(visited,i);
        }
    }
    
    cout<<endl<<"No, of components in graph are: "<<count<<endl;
    
    return 0;
}
