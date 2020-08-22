#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define N 6
bool issink(bool g[N][N],int i)
{
    for(int j=0;j<N;j++)
    {
        if(g[i][j]==1)
            return false;
        if(g[j][i]==0 && j!=i)
            return false;
    }
    return true;
}

int eliminate(bool g[N][N])
{
    int i=0,j=0;
    
    while(i<N && j<N )
    {
        if(g[i][j]==0)
            j=j+1;
        else
            i=i+1;
    }
    if(i>N)
        return -1;
    else if(!issink(g,i))
        return -1;
    else return i;
}


int main() 
{ 
    // Let us create a bpGraph  
    // shown in the above example 
    bool g[N][N] = {{0, 0, 0, 0, 0, 1}, 
                          {0, 0, 0, 0, 0, 1}, 
                          {0, 0, 0, 0, 0, 1}, 
                          {0, 0, 0, 0, 0, 1}, 
                          {0, 0, 0, 0, 0, 1}, 
                          {0, 0, 0, 0, 0, 1}}; 
  
    int ver=eliminate(g);
    if(ver>=0)
        cout<<"Sink found at vertex "<<ver+1<<endl;
    else
       cout<<"No sink"<<endl; 
    
  
    return 0; 
} 
