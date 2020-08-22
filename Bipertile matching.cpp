#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define M 6
#define N 6

bool bpm(bool bpGraph[M][N],int u, bool seen[],int matchR[])
{
    for(int v=0;v<N;v++)
    {
        if(bpGraph[u][v] && !seen[v])
        {
            seen[v]=true;
            if(matchR[v]<0 ||bpm(bpGraph,matchR[v],seen,matchR))
            {
                matchR[v]=u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(bool bpGraph[M][N])
{
    int *matchR=new int[N];
    bool *seen=new bool[N];
    for(int i=0;i<N;i++)
    {
        matchR[i]=-1;
        seen[i]=false;
    }
    int result=0;
    for(int u=0;u<M;u++)
    {
        if(bpm(bpGraph,u,seen,matchR))
            result++;    
    }
    return result;
}

int main() 
{ 
    // Let us create a bpGraph  
    // shown in the above example 
    bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0}, 
                          {1, 0, 0, 1, 0, 0}, 
                          {0, 0, 1, 0, 0, 0}, 
                          {0, 0, 1, 1, 0, 0}, 
                          {0, 0, 0, 0, 0, 0}, 
                          {0, 0, 0, 0, 0, 1}}; 
  
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph); 
  
    return 0; 
} 
