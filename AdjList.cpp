#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(list<int>L[],int n)
{
    cout<<"Content of Adjacency List"<<endl;
    for(int i=0;i<n;i++)
    {   
        cout<<i<<"--->"<<" ";
        list<int>::iterator it;
        for(auto it=L[i].begin();it!=L[i].end();++it)
            cout<<*it<<" ";
        cout<<endl;
    }
}
void addEdge(list<int>L[],int i, int j)
{
    L[i].push_back(j);
}
void removeEdge(list<int>L[],int i,int j)
{
    
    list<int>::iterator it,it2;
    it2=L[i].begin();
    for(auto it=L[i].begin();it!=L[i].end();++it)
    {
        if(*it==j)
        {
            L[i].erase(it);
            break;
            
        }
           
    }
}
int main()
{
    int n=4;
    list<int>L[n];
    addEdge(L,0,1);
    addEdge(L,2,1);
    addEdge(L,0,3);
    addEdge(L,2,3);
    addEdge(L,2,0);
    removeEdge(L,2,0);
    print(L,n);
    return 0;
}
