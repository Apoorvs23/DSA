//https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
    private:
    void dfs(vector<int> adj[],int start, stack<int> &topo,vector<int>&vis)
    {
        vis[start]=1;
        for(auto p:adj[start])
        {
            if(!vis[p]) dfs(adj,p,topo,vis);
        }
        topo.push(start);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(n,0);
	    stack<int> topo;
	    vector<int> topoSort;
	    for(int i=0;i<n;i++)
	    {
	        if(!vis[i]) dfs(adj,i,topo,vis);
	    }
	    while(!topo.empty())
	    {
	        int top=topo.top();
	         topoSort.push_back(top);
	         topo.pop();
	    }
	    return topoSort;
	    
	}
};