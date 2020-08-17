#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Graph
{
  int v;
  list<pair<int,int>>*l;
  public:
    Graph(int n)
    {
        v=n;
        l=new list<pair<int,int>>[v];
    }
    void addEdge(int i, int j,int w);
    void shortestPath(int s);
};

void Graph::addEdge(int i,int j,int w)
{
    l[i].push_back(make_pair(j,w));
    l[j].push_back(make_pair(i,w));
}

void print(int i, int path[])
{
    if(path[i]==-1)
        return;
    print(path[i],path);
    cout<<"-->"<<i;
}

void Graph::shortestPath(int s)
{
    vector<int>dist(v,INT_MAX);
    int path[v];
    
    dist[s]=0;
    path[s]=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        
        list<pair<int,int>>::iterator it;
        for(auto it=l[u].begin();it!=l[u].end();++it)
        {
            int v=(*it).first;
            int w=(*it).second;
            
            if(dist[v]>dist[u]+w)
             {  
                 dist[v]=dist[u]+w;
                 path[v]=u;
                 q.push(make_pair(dist[v],v));
             }
            
        }
    }
    
   
    for(int i=0;i<v;i++)
    {
       cout<<s;
       print(i,path);
       cout<<"  :"<<dist[i]<<endl;
    }
}

int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    cout<<"shortest Distance using Dijkstra's algorithm "<<endl;
    g.shortestPath(0); 
  
    
    return 0;
}
