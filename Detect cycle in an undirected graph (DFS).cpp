//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
    private:
    bool dfs(int start,vector<int> adj[],vector<int>&vis,int parent)
    {
        vis[start]=1;
        for(auto p:adj[start])
        {
            if(!vis[p]) 
            {
                if(dfs(p,adj,vis,start)) return true;
            }
            else if(parent!=p) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,-1)) return true;;  // if there is a cycle in any of the graph component -return true
            }
        }
        return false;
    }
};