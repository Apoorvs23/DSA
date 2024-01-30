//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
private:
bool dfs(vector<int> adj[],vector<int> &vis,int start)
{
    vis[start]=2;
    for(auto p:adj[start])
    {
        if(vis[p]==0)
        {
            if(dfs(adj,vis, p)) return true;
        }
        else if(vis[p]==2) return true;
    }
    vis[start]=1;
    return false;
}
 // 1 will be for visited, 2 for path visited and 0 is for unvisited
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0 && dfs(adj,vis,i)) return true;
        }
        return false;
    }
};