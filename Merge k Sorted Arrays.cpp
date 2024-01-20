
//O(NK log K) ( NK total elements -Log K to insert and Log K to delete)

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> v, int K)
    {
        //code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<int> sortedArray;
        for(int i=0;i<K;i++)
        {
            q.push({v[i][0],{i,0}});
        }
        //maitain the size of heap to be not more than K
        while(!q.empty())
        {
            int e=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            sortedArray.push_back(e);
            if(c+1<v[r].size())  q.push({v[r][c+1],{r,c+1}});
        }
        return sortedArray;
    }
};