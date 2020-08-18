#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<pair<int,int>> *l;
    public:
    Graph(int n)
    {
        v=n;
        l=new list<pair<int,int>>[v];
    }
    void addEdge(int i, int j,int w);
    void prims();
};

void Graph::addEdge(int i, int j, int w)
{
    l[i].push_back(make_pair(j,w));
    l[j].push_back(make_pair(i,w));
}

void Graph::prims()
{
    int s=0;
    vector<int>key(v,INT_MAX);
    vector<bool>vist(v,false);
    vector<int>path(v,-1);
    path[s]=-1;
    key[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    
    p.push(make_pair(key[s],s));
    
    
    while(!p.empty())
    {
        int u=p.top().second;
        p.pop();
        
        vist[u]=true;
        
        list<pair<int,int>>::iterator it;
        for(auto it=l[u].begin();it!=l[u].end();++it)
        {
            int v=(*it).first;
            int w=(*it).second;
            if(!vist[v] && key[v]>w)
            {
                key[v]=w;
                p.push(make_pair(key[v],v));
                path[v]=u;
            }
        }
    }
    int sum=0;
    for(int i=1;i<v;i++)
    {
        cout<<path[i]<<"-->"<<i<<" "<<key[i]<<endl;
        sum+=key[i];
    }
    cout<<"Cost of MST is "<<sum<<endl;
    
}

int main()
{
    int n=9;
    Graph g(n);
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
    
    cout<<"Edges in prims algorithm "<<endl;
    g.prims();
   
    return 0;
}

