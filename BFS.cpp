//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) { //0 based graph
       
     //   int n=adj[].size(); -- n are no. of nodes
        int isVisited[n]={0};
        isVisited[0]=1;
        queue<int> q;
        q.push(0);
        //take everyting till queue is not empty
        vector<int> bfs;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node])
            {
                if(!isVisited[it])
                {
                    q.push(it);
                    isVisited[it]=1;
                }
                
            }
        }
        return bfs;
    }
};