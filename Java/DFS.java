class Solution {
    // Function to return a list containing the DFS traversal of the graph.
    public void DFS(int V, ArrayList<ArrayList<Integer>>adj, boolean[] visited, ArrayList<Integer> res)
    {
        visited[V]=true;
        res.add(V);
        
        for(int node:adj.get(V))
        {
            if(!visited[node])
            {
                DFS(node, adj, visited, res);
            }    
        }
    }
    
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> result = new ArrayList<Integer>();
        boolean visited[] = new boolean[V];
        for(int i=0;i<V;i++)
            visited[i]=false;
        
        
        DFS(0, adj, visited, result);
 
        return result;
    }
}
