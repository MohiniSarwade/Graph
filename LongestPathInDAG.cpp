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
    void longestPath(int s);
    void topologicalSort(int s, bool vist[], stack<int>&st);
};

void Graph::addEdge(int i,int j,int w)
{
    l[i].push_back(make_pair(j,w));
   
}

void print(int i, int path[])
{
    if(path[i]==-1)
        return;
    print(path[i],path);
    cout<<"-->"<<i;
}

void Graph::topologicalSort(int s, bool vist[], stack<int>&st)
{
    vist[s]=true;
    
    for(auto it=l[s].begin();it!=l[s].end();++it)
    {
        if(!vist[(*it).first])
            topologicalSort((*it).first,vist,st);
    }
    st.push(s);
}

void Graph::longestPath(int s)
{
    vector<int>dist(v,INT_MIN);
    int path[v];
    stack<int>st;
    
    dist[s]=0;
    path[s]=-1;
    bool *vist=new bool[v];
    for(int i=0;i<v;i++)
        vist[i]=false;
    
    for(int i=0;i<v;i++)
    {
        if(!vist[i])
            topologicalSort(i,vist,st);
    }
    
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        
        list<pair<int,int>>::iterator it;
        if(dist[u]!=INT_MIN)
        {
        for(auto it=l[u].begin();it!=l[u].end();++it)
        {
            int v=(*it).first;
            int w=(*it).second;
            
            if(dist[v]<dist[u]+w)
             {  
                 dist[v]=dist[u]+w;
                 path[v]=u;
             }
            
        }
        }
    }
    
     for (int i = 0; i < v; i++)  
        (dist[i] == INT_MIN) ? cout << "INF " : cout << dist[i] << " "; 
   
   /* for(int i=0;i<v;i++)
    {
       cout<<s;
       print(i,path);
       cout<<"  :"<<dist[i]<<endl;
    }*/
}


int main()
{
    Graph g(6);  
    g.addEdge(0, 1, 5);  
    g.addEdge(0, 2, 3);  
    g.addEdge(1, 3, 6);  
    g.addEdge(1, 2, 2);  
    g.addEdge(2, 4, 4);  
    g.addEdge(2, 5, 2);  
    g.addEdge(2, 3, 7);  
    g.addEdge(3, 5, 1);  
    g.addEdge(3, 4, -1);  
    g.addEdge(4, 5, -2);  
    
    int s = 1;  
    cout << "Following are longest distances from "
            "source vertex "
         << s << " \n";  
    g.longestPath(s);  

return 0;
}
