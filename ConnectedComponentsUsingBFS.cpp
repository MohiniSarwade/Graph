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
  void BFS();
  void BFSUtil(int s, bool visit[]);
};
void Graph::addEdge(int i, int j)
{
    l[i].push_back(j);
    l[j].push_back(i);
}

void Graph::BFSUtil(int s,bool visit[])
{
    std::queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        visit[s]=true;
        
        list<int>::iterator it;
        for(auto it=l[s].begin();it!=l[s].end();++it)
            if(!visit[*it])
                q.push(*it);
    }
}

void Graph::BFS()
{
    bool *visit=new bool[v];
    for(int i=0;i<v;i++)
        visit[i]=false;
    
    int count=0;
    for(int i=0;i<v;i++)
    {
       if(!visit[i])
       {
           count++;
           BFSUtil(i,visit);
       }
        
    }
    cout<<count<<endl;
}
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(5); // 5 vertices numbered from 0 to 4 
    g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are connected components \n"; 
    g.BFS(); 
  
    return 0; 
} 
