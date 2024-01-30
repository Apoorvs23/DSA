//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        vector<int> dis(n,1e9);
        st.insert({0,S});
        dis[S]=0;
        while(!st.empty())
        {
            auto it=*(st.begin()); //point to the begin of the set and get value/ *-> will give you the value
            int node=it.second;
            int distance=it.first;
            st.erase(it);
            for(auto p:adj[node])
            {
                int adjNode=p[0];
                int adjDistance=p[1];
                if(distance+adjDistance<dis[adjNode])
                {
                    //erase if existed
                    if(dis[adjNode]!=1e9) st.erase({dis[adjNode],adjNode});
                    dis[adjNode]=distance+adjDistance;
                    st.insert({dis[adjNode],adjNode});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
    }
};