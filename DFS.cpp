//https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
    private :
    void dfs(int visited[],vector<int> adj[],vector<int> &dfsList,int start)
    {
        visited[start]=1;
        dfsList.push_back(start);
        for(auto p:adj[start]) //traverse all the neighbours
        {
            if(!visited[p])
            {
            
                dfs(visited,adj,dfsList,p);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
      int visited[n]={0};
     vector<int> dfsList;
     int start=0; //taking 0 as starting node
     dfs(visited,adj,dfsList,start);
      return dfsList;
    }
};