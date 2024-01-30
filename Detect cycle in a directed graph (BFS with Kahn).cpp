//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
     private:
    bool bfs(vector<int> adj[],int &count, vector<int> &inOrder, int n)
    {
        for(int i=0;i<n;i++)
        {
            for(auto p:adj[i])
            {
                inOrder[p]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(inOrder[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int top=q.front();
         //   topoSort.push_back(top);
            q.pop();
         count++;
            for(auto p:adj[top])
            {
                inOrder[p]--;
                if(inOrder[p]==0) q.push(p);
            }
         
        }
        return(count==n);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	bool isCyclic(int n, vector<int> adj[]) 
	{
	    // code here
	  //  vector<int> topoSort;
	   vector<int> inOrder(n,0);
	   int count=0;
	   return  !bfs(adj,count,inOrder,n);
	   
 
	}
};
