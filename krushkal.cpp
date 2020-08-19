#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest,w;
};
class Graph
{
    int v,e;
    int *p,*r;
    public:
    struct Edge *edge;
    Graph(int n,int t)
    {
        v=n;
        e=t;
        p=new int[v];
        r=new int[v];
        edge=new Edge[e];
    }
    void union_s(int x, int y);
    void makeset();
    int find(int i);
    //int myComp(const void* a, const void* b);
    void Kruskal();
};

void Graph::makeset()
{
    for(int i=0;i<v;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int Graph::find(int x)
{
    while(x!=p[x])
    {
        x=p[x];
    }
    return x;
}
void Graph::union_s(int x, int y)
{
    int t1=find(x);
    int t2=find(y);
    if(t2==t1)
        return;
        
    if(r[t1]>r[t2])
		p[t2]=t1;
	else
		p[t1]=t2;
		
	if(r[t1]==r[t2])
		r[t2]=r[t2]+1;
}
int myComp(const void* a, const void* b)  
{  
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->w > b1->w;  
} 
void Graph:: Kruskal()
{
    vector<Edge>res;
    int cost=0;
   
    makeset();
    qsort(edge,e,sizeof(edge[0]),myComp);
    
    for(int i=0;i<e;i++)
    {
        if(find(edge[i].src)!=find(edge[i].dest))
        {
            cout<<edge[i].src<<"-->"<<edge[i].dest<<" "<<edge[i].w<<endl;
            cost+=edge[i].w;
            union_s(edge[i].src,edge[i].dest);
        }
    }
    
    
        
        
    cout<<"Cost of MST is "<<cost;
}

int main()
{
     /* Let us create following weighted graph  
            10  
        0--------1  
        | \ |  
    6| 5\ |15  
        | \ |  
        2--------3  
            4 */
    int V = 4; // Number of vertices in graph  
    int E = 5; // Number of edges in graph  
    Graph graph =Graph(V, E);  
  
  
    // add edge 0-1  
    graph.edge[0].src = 0;  
    graph.edge[0].dest = 1;  
    graph.edge[0].w = 10;  
  
    // add edge 0-2  
    graph.edge[1].src = 0;  
    graph.edge[1].dest = 2;  
    graph.edge[1].w = 6;  
  
    // add edge 0-3  
    graph.edge[2].src = 0;  
    graph.edge[2].dest = 3;  
    graph.edge[2].w = 5;  
  
    // add edge 1-3  
    graph.edge[3].src = 1;  
    graph.edge[3].dest = 3;  
    graph.edge[3].w = 15;  
  
    // add edge 2-3  
    graph.edge[4].src = 2;  
    graph.edge[4].dest = 3;  
    graph.edge[4].w = 4;  
  
    graph.Kruskal();  

    
    
    return 0;
}
