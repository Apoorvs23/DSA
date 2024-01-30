//https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
    private:
    void bfs(vector<int> adj[],vector<int> &topoSort, vector<int> &inOrder, int n)
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
            topoSort.push_back(top);
            for(auto p:adj[top])
            {
                inOrder[p]--;
                if(inOrder[p]==0) q.push(p);
            }
            q.pop();
        }
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    // code here
	    vector<int> topoSort;
	    vector<int> inOrder(n,0);
	    bfs(adj,topoSort,inOrder,n);
	    return topoSort;
	    
	}
};