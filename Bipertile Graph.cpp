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
  bool isBipertile();
  bool isBipertileUtil(int s, int color[]);
  void addEdge(int i, int j);    
};

void Graph::addEdge(int i, int j)
{
    l[i].push_back(j);
    l[j].push_back(i);
}

bool Graph:: isBipertileUtil(int s, int color[])
{
    queue<int>q;
    q.push(s);
    
    color[s]=1;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        
        for(auto it=l[s].begin();it!=l[s].end();++it)
        {
            if(s==*it)
                return false;
            if(color[*it]==-1)
            {
                color[*it]=1-color[s];
                q.push(*it);
            }
            else if(color[s]==color[*it])
                return false;
        }
        
    }
    return true;
}

bool Graph::isBipertile()
{
     int *color=new int[v];
    for(int i=0;i<v;i++)
        color[i]=-1;
   
    for (int i = 0; i < v; i++) 
    if (color[i] == -1) 
        if (isBipertileUtil(i, color) == false) 
        return false; 
  
    return true; 
}
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
 
    
    if(g.isBipertile())
        cout<<"Grpah is Bipertile"<<endl;
    else
        cout<<"Grpah is not Bipertile"<<endl;
    
    return 0;
}
