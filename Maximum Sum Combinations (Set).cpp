//Problem Link: https://www.geeksforgeeks.org/problems/maximum-sum-combination/1


class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
       sort(A.begin() , A.end());
       sort(B.begin() , B.end());
       priority_queue<pair<int,pair<int,int>>> q; // sum, a[i],b[i]
       set<pair<int,int>> s;
       q.push({A[N-1]+B[N-1],{N-1,N-1}});
       s.insert({N-1,N-1});
       vector<int> ans;
       while(K--)
       {
           int sum=q.top().first;
           int a=q.top().second.first;
           int b=q.top().second.second;
           ans.push_back(sum);
           q.pop();
           if(a-1>=0 && s.find({a-1,b})==s.end()) 
           {
               q.push({A[a-1]+B[b],{a-1,b}});
               s.insert({a-1,b});
           }
           if(b-1>=0 && s.find({a,b-1})==s.end())
           {
               q.push({A[a]+B[b-1],{a,b-1}});
               s.insert({a,b-1});
           }
       }
       
       return ans;
    }
};