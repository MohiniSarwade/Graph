#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src,dest,weight;
};
class Graph{
  int v,e;
 
  public:
   struct Edge *edge;
  Graph(int V,int E)
  {
      v=V;
      e=E;
      edge=new Edge[e];
      return;
  }
   
  void BellmanFord(int s);  
};
void print(int i, int path[])
{
    if(path[i]==-1)
        return;
    print(path[i],path);
    cout<<"-->"<<i;
}

void Graph::BellmanFord(int s)
{
    int d[v];
    int path[v];
    for(int i=0;i<v;i++)
        d[i]=INT_MAX;
    d[s]=0;
    path[s]=-1;
    
    for(int i=1;i<=v-1;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u=edge[j].src;
            int v=edge[j].dest;
            int w=edge[j].weight;
            if(d[u]!=INT_MAX &&d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                path[v]=u;
            }
        }
    }
    
     for(int j=0;j<e;j++)
        {
            int u=edge[j].src;
            int v=edge[j].dest;
            int w=edge[j].weight;
            if(d[u]!=INT_MAX &&d[u]+w<d[v])
            {
                cout<<"Graph contains negative edge cycyle"<<endl;
                return;
            }
        }
    for(int i=0;i<v;i++)
    {
       cout<<s;
       print(i,path);
       cout<<"  :"<<d[i]<<endl;
    }
}

int main()
{
    int V = 5; 
    int E = 8;
    Graph graph(V, E); 
  
    graph.edge[0].src = 0; 
    graph.edge[0].dest = 1; 
    graph.edge[0].weight = -1; 
  
    graph.edge[1].src = 0; 
    graph.edge[1].dest = 2; 
    graph.edge[1].weight = 4; 
  
    graph.edge[2].src = 1; 
    graph.edge[2].dest = 2; 
    graph.edge[2].weight = 3; 
  
    graph.edge[3].src = 1; 
    graph.edge[3].dest = 3; 
    graph.edge[3].weight = 2; 
  
    graph.edge[4].src = 1; 
    graph.edge[4].dest = 4; 
    graph.edge[4].weight = 2; 
  
    graph.edge[5].src = 3; 
    graph.edge[5].dest = 2; 
    graph.edge[5].weight = 5; 
  
    graph.edge[6].src = 3; 
    graph.edge[6].dest = 1; 
    graph.edge[6].weight = 1; 
  
    graph.edge[7].src = 4; 
    graph.edge[7].dest = 3; 
    graph.edge[7].weight = -3; 
  
    cout<<"BellmanFord algorithm"<<endl;
    graph.BellmanFord(0); 
    
    return 0;
}
