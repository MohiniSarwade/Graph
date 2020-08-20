#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
    int V;
    list<int> *adjL; 
    int *in;
    Graph(int n)
    {
        V=n;
        adjL=new list<int>[V];
        in=new int[V];
        for(int i=0;i<V;i++)
            in[i]=0;
        
    }
    void addEdge(int u, int w);
    void DepthInDAG();
};

void Graph::addEdge(int u, int w)
{
    //for(int i=0;i<V;i++)
    //    cout<<in[i]<<" "; 
    //cout<<"In"<<endl;
     //cout<<w<<" "<<in[w]<<" ";
    adjL[u].push_back(w);
    in[w]++;
}

void printGraph(Graph g)
{
    //list<int>::iterator it;
    for(int i=0;i<g.V;i++)
        for(auto it=g.adjL[i].begin();it!=g.adjL[i].end();it++)
            cout<<i<<"-"<<*it<<endl;
}
void Graph::DepthInDAG()
{
    queue<int>q;
    int count=0;
   
    for(int i=0;i<V;i++)
        if(in[i]==0)
            q.push(i);
    q.push(-1);
    while(!q.empty())
    {
       int i=q.front();
        q.pop();
        if(i==-1)
        {
            count++;
            if(!q.empty())
                q.push(-1);
        }
        else
        {
            for(auto it=adjL[i].begin();it!=adjL[i].end();++it)
                if(--in[*it]==0)
                    q.push(*it);
        }
    }
    cout<<"The depth of DAG is "<<count<<endl;
}

int main() 
{ 
                   
    Graph g(4); 
    
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 3);
    printGraph(g);
    g.DepthInDAG();
    
    return 0; 
} 
