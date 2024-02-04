//https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
class Solution {
    
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        priority_queue< int,vector<int>,greater<int>> q;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++) // O(n2)
            {
                if(q.size()==K)
                {
                  if(q.top()<A[i]+B[j])
                  {
                      q.pop();
                  }
                  else
                  {
                      continue;
                  }
                }
                q.push(A[i]+B[j]);  //pushing in priority takes logK 
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};