#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define V 6

bool BFS(int rgraph[V][V],int s,int t,int prt[])
{
    bool *vist=new bool[V];
    for(int i=0;i<V;i++)
    {
        vist[i]=false;
    }
    vist[s]=true;
     prt[s]=-1;
    
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(int i=0;i<V;i++)
        {
            if(!vist[i] && rgraph[s][i]>0)
            {
                prt[i]=s;
                q.push(i);
                vist[i]=true;
            }
        }
    }
    return (vist[t]==true);
        
}
int fordFulkerson(int graph[V][V], int s, int t)
{
    int rgraph[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
            rgraph[i][j]=graph[i][j];
    }
    int *prt=new int[V];
   
    int maxflow=0;
    
    while((BFS(rgraph,s,t,prt)))
    {
        int pathflow=INT_MAX;
        for(int i=t;i!=s;i=prt[i])
        {
            int u=prt[i];
            pathflow=min(pathflow,rgraph[u][i]);
        }
        for(int i=t;i!=s;i=prt[i])
        {
             int u=prt[i];
            rgraph[u][i]-=pathflow;
            rgraph[i][u]+=pathflow;
        }
        maxflow+=pathflow;
    }
    return maxflow;
}
int main() 
{ 
    // Let us create a graph shown in the above example 
    int graph[V][V] = { {0, 16, 13, 0, 0, 0}, 
                        {0, 0, 10, 12, 0, 0}, 
                        {0, 4, 0, 0, 14, 0}, 
                        {0, 0, 9, 0, 0, 20}, 
                        {0, 0, 0, 7, 0, 4}, 
                        {0, 0, 0, 0, 0, 0} 
                      }; 
  
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5); 
  
    return 0; 
} 
