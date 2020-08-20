#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  list<int>*l;
  int *in;
  public:
  Graph(int n)
  {
      v=n;
      l=new list<int>[v];
      in=new int[v];
      for(int i=0;i<v;i++)
        in[i]=0;
  }
  void addEdge(int i,int j);
  bool isEulerianCycle();
  void DFS(int s, bool visit[]);
  Graph getTranspose();
  bool isSC();
};
void Graph::addEdge(int i, int j)
{
    l[i].push_back(j);
}
void Graph::DFS(int s, bool visit[])
{
    visit[s]=true;
    
    list<int>::iterator it;
    for(auto it=l[s].begin();it!=l[s].end();++it)
        if(!visit[*it])
            DFS(*it,visit);
}
Graph Graph::getTranspose()
{
    Graph g(v);
    for(int i=0;i<v;i++)
    {
        list<int>::iterator it;
        for(auto it=l[i].begin();it!=l[i].end();++it)
        {
            g.l[*it].push_back(i);
            in[i]++;
        }
    }
    return g;
}

bool Graph::isSC()
{
    bool visit[v];
  
    
    for(int i=0;i<v;i++)
    {
        visit[i]=false;
        
    }
    int i;
    for(i=0;i<v;i++)
    {
        if(l[i].size()>0)
            break;
    }

    DFS(i,visit);
    for(i=0;i<v;i++)
    {
        if(!visit[i] && l[i].size()>0)
            return false;
    }
    
    Graph gr=getTranspose();
    for(i=0;i<v;i++)
    {
        if(l[i].size()>0)
            break;
    }
    DFS(i,visit);
    for(i=0;i<v;i++)
    {
        if(!visit[i] && l[i].size()>0)
            return false;
    }
        
    return true;
}

bool Graph::isEulerianCycle()
{
    if(isSC()==false)
        return false;
    
    for(int i=0;i<v;i++)
    {
        if(in[i]!=l[i].size())
            false;
    }
    return true;
}
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 0); 
  
    if (g.isEulerianCycle()) 
       cout << "Given directed graph is eulerian"; 
    else
       cout << "Given directed graph is NOT eulerian"; 
    return 0; 
} 
