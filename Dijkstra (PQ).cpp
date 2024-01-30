//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //min heap
        vector<int> dist(n,1e9);
        dist[S]=0;
        pq.push({0,S}); // distance is 0 from S to S
        while(!pq.empty())
        {
            int distance=pq.top().first;
            int Node=pq.top().second;
            pq.pop();
            for(auto p:adj[Node])
            {
                int adjDistance=p[1];
                int adjNode=p[0];
                if(distance+adjDistance<dist[adjNode])
                {
                    dist[adjNode]=distance+adjDistance;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};
// TC:
// => O(no. of times queue run * (pop vertix from minheap (log(heapize))+for loop that goes on adjacent))
// => O(V * (O(q.top)+no. of edges in each vertix * q.push));
// => O(V * (O(log(heapSize))+V-1* log(heapSize)));
// Taking log(heapSize) common
// heapsize = each V pushes more V nodes (V-1)+(V-1)+(V-1)+(V-1)...... =  (VxV)
// => O(V*log(heapSize)(1+V-1))
// => O(V*log(V^2)*V)
// => O(V^2log(V^2))
// => O9=(2 x V^2(LogV))
// => O(V*V*LogV) (VxV=E)  ( if one node is connected to each and every node and total edges = O(V*(V-1))) edges;
// =>ElgoV