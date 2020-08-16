#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int v;
    list<int>*AL;
    public:
    Graph(int n)
    {
        v=n;
        AL=new list<int>[v];
    }
    void addEdge(int i, int j);
    void BFS(int s);
};

void Graph::addEdge(int i, int j)
{
    AL[i].push_back(j);
}
void Graph::BFS(int s)
{
    bool *vist=new bool[v];
    for(int i=0;i<v;i++)
        vist[i]=false;
    queue<int>q;
    vist[s]=true;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        cout<<s<<" ";
        
        list<int>::iterator it;
        for(auto it=AL[s].begin();it!=AL[s].end();++it)
        {
            if(!vist[*it])
            {
                vist[*it]=true;
                q.push(*it);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    cout<<"BFS Traversal of Graph "<<endl;
    g.BFS(2);
    return 0;
}
