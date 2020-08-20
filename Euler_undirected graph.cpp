#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
  int v;
  list<int>*l;
  public:
    Graph(int n)
    {
        v=n;
        l=new list<int>[v];
    }
    void test();
    void addEdge(int i, int j);
    bool isConnected();
    int isEuler();
    void DFS(int s, bool visit[]);
};

void Graph::addEdge(int i, int j)
{
    l[i].push_back(j);
    l[j].push_back(i);
}

void Graph::DFS(int s, bool visit[])
{
    visit[s]=true;
    
    list<int>::iterator it;
    for(auto it=l[s].begin();it!=l[s].end();++it)
    {
        if(!visit[*it])
            DFS(*it,visit);
    }
}

bool Graph::isConnected()
{
    bool visit[v];
    for(int i=0;i<v;i++)
        visit[i]==false;
        
    int i;
    for(i=0;i<v;i++)
        if(l[i].size()>0)
            break;
    if(i==v)
        return true;
    
    DFS(i,visit);
    
    for(i=0;i<v;i++)
    {
        if(visit[i]==false && l[i].size()>0)
            return false;
    }
    
    return true;
}

int Graph::isEuler()
{
    if(isConnected()==false)
        return 0;
    int odd=0;
    for(int i=0;i<v;i++)
    {
        if(l[i].size() & 1)
            odd++;
    }
    if(odd>2)
        return 0;
    return (odd)?1:2;
}
void Graph::test()
{
    int res=isEuler();
    if(res==0)
        cout<<"No Eluer path or cycle exist"<<endl;
    if(res==1)
        cout<<"Euler path exist(Semi Eluer)"<<endl;
    if(res==2)
        cout<<"Euler cycle exist"<<endl;
}
int main()
{
    cout<<"Graph 1"<<endl;
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.test(); 
  
    cout<<"Graph 2"<<endl;
    Graph g2(5); 
    g2.addEdge(1, 0); 
    g2.addEdge(0, 2); 
    g2.addEdge(2, 1); 
    g2.addEdge(0, 3); 
    g2.addEdge(3, 4); 
    g2.addEdge(4, 0); 
    g2.test(); 
    
    cout<<"Graph 3"<<endl;
    Graph g3(5); 
    g3.addEdge(1, 0); 
    g3.addEdge(0, 2); 
    g3.addEdge(2, 1); 
    g3.addEdge(0, 3); 
    g3.addEdge(3, 4); 
    g3.addEdge(1, 3); 
    g3.test(); 
  
    // Let us create a graph with 3 vertices 
    // connected in the form of cycle 
     cout<<"Graph 4"<<endl;
    Graph g4(3); 
    g4.addEdge(0, 1); 
    g4.addEdge(1, 2); 
    g4.addEdge(2, 0); 
    g4.test(); 
  
    // Let us create a graph with all veritces 
    // with zero degree 
    cout<<"Graph 5"<<endl;
    Graph g5(3); 
    g5.test(); 
    
return 0;
}
