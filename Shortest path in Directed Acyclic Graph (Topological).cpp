//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
class Solution {
    private:
    void dfsTopoSort(vector<pair<int,int>> adj[],stack<int> &s,vector<int> &vis,int start )
    {
        vis[start]=1;
        for(auto p:adj[start])
        {
            int v=p.first;
            if(!vis[v]) dfsTopoSort(adj,s,vis,v);
        }
        s.push(start);
    }
  public:
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
        // code here
       // edge = [[0,1,2],[0,2,1]] ->  [[u,v,weight]]
       vector<pair<int,int>> adj[n];
      for(auto p:edges)
      {
          int u=p[0];
          int v=p[1];
          int d=p[2];
          adj[u].push_back({v,d});
      }
    vector<int> vis(n,0);
    stack<int> s;
    //find toposort
    for(int i=0;i<n;i++)
    {
        // O(n+e)
        if(!vis[i]) dfsTopoSort(adj,s,vis,i);
    }
    vector<int> distance(n,1e9);
    // vector<int> distance(n);
    // for(int i=0;i<n;i++) distance[i]=INT_MAX;
    distance[0]=0; //starting from  0th node and distance from 0th node to 0th node is 0
    // O(n+m)
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        for(auto u:adj[node])
        {
            int v=u.first;
            int d=u.second;
            if(distance[node]+d<distance[v]) distance[v]=distance[node]+d; //relaxtion
            
        }
    }
    for(int i=0;i<n;i++)
    {
        if(distance[i]==1e9) distance[i]=-1;
    }
    return distance;
}
};