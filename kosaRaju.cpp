#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  list<int>*l;
 
  public:
  Graph(int n)
  {
      v=n;
      l=new list<int>[v];
      
  }
  void addEdge(int i,int j);
  void printSCCs();
  void DFS(int s, bool visit[]);
  Graph getTranspose();
  void fillOrder(int s, bool visit[], stack<int>&st);
  
};
void Graph::addEdge(int i, int j)
{
    l[i].push_back(j);
}
void Graph::DFS(int s, bool visit[])
{
    visit[s]=true;
    cout<<s<<" ";
    
    list<int>::iterator it;
    for(auto it=l[s].begin();it!=l[s].end();++it)
        if(!visit[*it])
            DFS(*it,visit);
}
Graph Graph::getTranspose()
{
    Graph g(v);
    for(int i=0;i<v;i++)
    {
        list<int>::iterator it;
        for(auto it=l[i].begin();it!=l[i].end();++it)
        {
            g.l[*it].push_back(i);
           
        }
    }
    return g;
}

void Graph::fillOrder(int s, bool visit[], stack<int>&st)
{
    visit[s]=true;
   
    list<int>::iterator it;
    for(auto it=l[s].begin();it!=l[s].end();++it)
        if(!visit[*it])
            fillOrder(*it,visit,st);
    
    st.push(s);
}

void Graph::printSCCs()
{
    bool *visit = new bool[v]; 
    for(int i=0;i<v;i++)
        visit[i]=false;
        
    stack<int>st;
    
    for(int i=0;i<v;i++)   
        if(!visit[i])
            fillOrder(i,visit,st);
        
    Graph gr=getTranspose();
    
    for(int i=0;i<v;i++)
        visit[i]=false; 
        
    while(st.empty()==false)
    {
       int x=st.top();
       st.pop();
      if(visit[x]==false) 
       {
           gr.DFS(x,visit);
           cout<<endl;
       }
    }
    
}
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
   
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.printSCCs(); 
    return 0; 
} 
