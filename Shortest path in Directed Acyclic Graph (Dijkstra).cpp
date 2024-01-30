//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& v){
        // code here
        vector<pair<int,int>> adj[N];
        for(auto p:v)
        {
            adj[p[0]].push_back({p[1],p[2]});
        }
        vector<int> d(N,1e9);
        d[0]=0;
        queue<int> q; //node
        q.push(0);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto p:adj[node])
            {
                if(d[node]+p.second<d[p.first])
                {
                    d[p.first]=d[node]+p.second;
                    q.push(p.first); // p is relaxed
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(d[i]==1e9) d[i]=-1;
        }
        return d;
    }
};