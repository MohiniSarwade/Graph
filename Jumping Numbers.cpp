void BFS(int i,int x,vector<int>&v)
{
    queue<int>q;
    q.push(i);
    
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        
        if(tmp<=x)
        {
            v.push_back(tmp);
            int k=tmp%10;
            
            if(k==0)
                q.push((tmp*10)+(k+1));
            else if(k==9)
                q.push((tmp*10)+(k-1));
            else
            {
                q.push((tmp*10)+(k+1));
                q.push((tmp*10)+(k-1));
            }
        }
    }
    sort(v.begin(),v.end());
    
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int x;
	    cin>>x;
	    vector<int>v;
	    v.push_back(0);
	    for(int i=1;i<=9 && i<=x;i++)
	        BFS(i,x,v);
	    for(int i=0;i<v.size();i++)
	        cout<<v[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
