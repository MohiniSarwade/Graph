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
    bool isCyclicUtil(bool vistied[],int start,int parent[]);
    bool isCyclic();
};

void Graph::addEdge(int u, int w)
{
    adjL[u].push_back(w);
    adjL[w].push_back(u);
}

bool Graph::isCyclicUtil(bool visited[],int i,int parent[])
{
    visited[i]=true;
  
    
    list<int>::iterator it;
    for(auto it=adjL[i].begin();it!=adjL[i].end();++it)
    {
       
        if(!visited[*it])
        {
            parent[*it]=i;
            if(isCyclicUtil(visited,*it,parent))
                return true;
        }
        else if(*it!=parent[i])
            return true;
          
    }
    return false;
}

bool Graph::isCyclic()
{
     bool *visited=new bool[V];
     int *parent=new int[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        parent[i]=-1;
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(isCyclicUtil(visited,i,parent))
                return true;
        }
    }
    return false;
}


int main() 
{ 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    return 0; 
} 
