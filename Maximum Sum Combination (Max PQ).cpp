//https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
//total complexity is O(nlong(n2))
class Solution {
    
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        //queue< int,vector<int>,greater<int>> q;
        priority_queue<int> q;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++) // O(n2)
            {
                q.push(A[i]+B[j]);  //pushing in priority takes logn 
            }
        }
        vector<int> ans;
        while(!q.empty() && K--)
        {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};