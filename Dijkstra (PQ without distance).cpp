//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

	public:
	class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dis(V,1e9);
        queue<int> q;
        q.push(S);
        dis[S]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto p:adj[node])
            {
               
                if(dis[node]+p[1]<dis[p[0]])
                {
                    dis[p[0]]=dis[node]+p[1];
                    q.push(p[0]);
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
    }
};
