//https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1
class Solution{
public:

    vector<int> replaceWithRank(vector<int> &v, int N){
    priority_queue< pair<int,int>, vector< pair<int,int>>, greater <pair<int,int> > > q;
    for(int i=0;i<N;i++)
    {
        q.push({v[i],i});
    }
    int rank=0;
    vector<int> rankVector(N);
    int prev=-1;
    while(!q.empty())
    {
        int val=q.top().first; //smalest
        int index=q.top().second;
        if(prev!=val)
        {
             rank++;
        }
       rankVector[index]=rank;
        
        q.pop();
        prev=val;
       
    }
    return rankVector;

    }

};