#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define V 5

bool isSafe(bool graph[V][V],int path[],int pos,int v)
{
    if(graph[path[pos-1]][v]==0)
        return false;
    
    for(int i=0;i<pos;i++)
    {
        if(path[i]==v)
            return false;
    }
   return true;
}

bool hamCycleUtil(bool graph[V][V],int path[],int pos)
{
    if(pos==V)
    {
        if(graph[path[pos-1]][path[0]]==1)
            return true;
        else
            return false;
    }
    for(int i=1;i<V;i++)
    {
        if(isSafe(graph,path,pos,i))
        {
            path[pos]=i;
            
            if(hamCycleUtil(graph,path,pos+1)==true)
                return true;
            
            path[pos]=-1;
        }
    }
    return false;
}

void printPath(int path[])
{
    cout<<"Solution exist. One possible cycle is "<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<path[0]<<endl;
}

bool hamCycle(bool graph[V][V])
{
    int *path=new int[V];
    for(int i=0;i<V;i++)
        path[i]=-1;
        
    path[0]=0;
    if(hamCycleUtil(graph,path,1)==false)
        {
            cout<<"Solution does not exist"<<endl;
            return false;
        }
 
    printPath(path);
    return true;
}

int main()  
{  
    /* Let us create the following graph  
        (0)--(1)--(2)  
        | / \ |  
        | / \ |  
        | / \ |  
        (3)-------(4) */
    bool graph1[V][V] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}};  
      
    // Print the solution  
    hamCycle(graph1);  
      
    /* Let us create the following graph  
    (0)--(1)--(2)  
    | / \ |  
    | / \ |  
    | / \ |  
    (3) (4) */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},  
                         {1, 0, 1, 1, 1},  
                         {0, 1, 0, 0, 1},  
                         {1, 1, 0, 0, 0},  
                         {0, 1, 1, 0, 0}};  
  
    // Print the solution  
    hamCycle(graph2);  
  
    return 0;  
}  
