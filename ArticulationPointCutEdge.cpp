#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
  
  int v;
  list<int> *l;
  void APHelper(int s, bool vist[], int disc[], int low[], int parent[], bool ap[]);
  public:
  Graph(int n)
  {
      v=n;
      l=new list<int>[v];
  }
  void AP();
  void addEdge(int i,int j);
  
};

void Graph::addEdge(int i, int j)
{
    l[i].push_back(j);
    l[j].push_back(i);
}

void Graph::APHelper(int s, bool vist[], int disc[], int low[], int parent[], bool ap[])
{
       static int time = 0;
        vist[s]=true;
        disc[s]=low[s]=++time;
      
        int children=0;
        list<int>::iterator it;
        for(auto it=l[s].begin();it!=l[s].end();++it)
        {
            int v=*it;
            if(!vist[v])
            {
                children++;
                parent[v]=s;
            
                APHelper(v,vist,disc,low,parent,ap);
                
                low[s]=min(low[v],low[s]);
                if(parent[s]==-1)
                {
                    if(children>1)
                         ap[s]=true;
                         
                    if(low[v]>disc[s])
                        cout<<s<<"->"<<v<<" is cut edge"<<endl;
                }
                   
                
                if(parent[s]!=-1)
                {
                    if(low[v]>=disc[s])
                        ap[s]=true;
                  
                    if(low[v]>disc[s])
                        cout<<s<<"->"<<v<<" is cut edge"<<endl;
                    
                }
                   
                
            }
            else if(v!=parent[s])
            {
                low[s]=min(disc[v],low[s]);
            }
        }
}
void Graph::AP()
{
   bool *vist = new bool[v]; 
    int *disc = new int[v]; 
    int *low = new int[v]; 
    int *parent = new int[v]; 
    bool *ap = new bool[v];
    
    for (int i = 0; i < v; i++) 
    { 
        parent[i] = -1; 
        vist[i] = false; 
        ap[i] = false; 
    } 
    for(int i=0;i<v;i++)
    {
        if(vist[i]==false)
            APHelper(i,vist,disc,low,parent,ap);
    }
   
   cout << "Articulation points are"<<endl;
    for(int i=0;i<v;i++)
    {
        if(ap[i]==true)
            cout<<i<<" ";
    }
  
    
}
int main()
{
    cout << "first graph \n";
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.AP(); 

    cout << "\nsecond graph \n"; 
    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.AP(); 
  
    cout << "\n third graph \n"; 
    Graph g3(7); 
    g3.addEdge(0, 1); 
    g3.addEdge(1, 2); 
    g3.addEdge(2, 0); 
    g3.addEdge(1, 3); 
    g3.addEdge(1, 4); 
    g3.addEdge(1, 6); 
    g3.addEdge(3, 5); 
    g3.addEdge(4, 5); 
    g3.AP(); 
    
    
    return 0;
}
