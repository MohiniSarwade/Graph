#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
  int v;
  list<int>*l;
  void topologicalSort(bool visit[],int s,stack<int> &st);
  public:
  Graph(int n)
  {
      v=n;
      l=new list<int>[v];
  }
  void addEdge(int i,int j);
  
  void topoHelper();
};

void Graph::addEdge(int i,int j)
  {
      l[i].push_back(j);
  }
  
void Graph::topologicalSort(bool visit[],int s,stack<int> &st)
{
    visit[s]=true;
    
    list<int>::iterator it;
    for(auto it=l[s].begin();it!=l[s].end();++it)
    {
        if(!visit[*it])
            topologicalSort(visit,*it,st);
    }
    st.push(s);
}
void Graph::topoHelper()
{
     bool *visit=new bool[v];
    for(int i=0;i<v;i++)
        visit[i]=false;
    stack<int>st;
    for(int i=0;i<v;i++)
    {
        if(!visit[i])
             topologicalSort(visit,i,st);
    }
    while(!st.empty())
    {
        int e=st.top();
        cout<<e<<" ";
        st.pop();
    }
}

int main()
{
    int n=8;
    Graph g(n);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,7);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(3,7);
    g.addEdge(4,6);
    
    cout<<"Topological sort of the Graph is "<<endl;
    g.topoHelper();
    return 0;
}
