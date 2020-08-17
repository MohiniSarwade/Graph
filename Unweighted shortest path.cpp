#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Graph
{
  int v;
  list<char> *l;
  public:
    Graph(int n)
    {
        v=n;
        l=new list<char>[v];
    }
    void addEdge(int i, int j);
    void unweightedShortestPath(int s);
};

void Graph::addEdge(int i,int j)
{
    l[i].push_back(j);
}

void Graph::unweightedShortestPath(int s)
{
    int *dist=new int[v];
    int *path=new int[v];
    char letter[v];
    
    char t='A';
   for(int i=0;i<v;i++)
    {
        dist[i]=-1;
        letter[i]=t;
        t++;
    }
    dist[s]=0;
    path[s]=s;
    queue<int>q;
    q.push(s);
    
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        
        list<int>::iterator it;
        for(auto it=l[s].begin();it!=l[s].end();++it)
        {
            if(dist[*it]==-1)
            {
                dist[*it]=dist[s]+1;
                path[*it]=s;
                q.push(*it);
            }
        }
    }
  
    for(int i=0;i<v;i++)
    {
        cout<<"C-->"<<letter[path[i]]<<"-->"<<letter[i]<<"-->"" "<<dist[i]<<endl;
    }
}

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,0);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(4,6);
    g.addEdge(5,6);
    
    g.unweightedShortestPath(2);
    
    
    return 0;
}
