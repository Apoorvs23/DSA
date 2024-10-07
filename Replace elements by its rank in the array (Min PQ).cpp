//https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(int i = 0; i< n; i++)
    {
        pq.push({arr[i],i});
    }
    int prev = -1;
    int rank = 0;
    vector<int> ans(n,0);
    while(!pq.empty())
    {
        if(prev!=pq.top().first)
            rank++;
        ans[pq.top().second] = rank;
        prev = pq.top().first;
        pq.pop();
        
    }
    return ans;

    }

};

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
       priority_queue< pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> > q;
       vector<int> rank(N,0);
       for(int i=0;i<N;i++)
       {
           q.push({arr[i],i});
       }
       int currentRank=0;
       int prev=-1;
       while(!q.empty())
       {
           int element=q.top().first;
           int index=q.top().second;
           q.pop();
           if(prev!=element) currentRank++;
           rank[index]=currentRank;
           prev=element;
       }
       return rank;

    }

};
