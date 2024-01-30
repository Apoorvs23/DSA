//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
    private:
    bool detect(int src,vector<int> adj[],int vis[])
    {
        vis[src]=1;
        queue<pair<int,int>> q; //child,parent
        q.push({src,-1}); //source come from -1 node
        
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjNode:adj[node])
            {
               if(!vis[adjNode])
               {
                   vis[adjNode]=1;
                   q.push({adjNode,node});
               }
               else if(parent!=adjNode) //it is a cycle 
               {
                   return true;
               }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        int vis[n]={0};
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && detect(i,adj,vis))
            {
            return true;
            }
        }
        return false;
    }
};