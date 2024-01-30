//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
private:
bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &visInPath,int start,int n )
{
    vis[start]=1;
    visInPath[start]=1;
    for(auto p:adj[start])
    {
        if(!vis[p])
        {
            if(dfs(adj,vis,visInPath, p, n)) return true;
        }
        else if(visInPath[p]) return true;
    }
    visInPath[start]=0;
    return false;
}
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n,0);
        vector<int> visInPath(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && dfs(adj,vis,visInPath,i,n)) return true;
        }
        return false;
    }
};