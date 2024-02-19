//https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1
class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        vector<int> temp= arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mp;
        int rank=1;
        for(auto p:temp)
        {
            if(mp.find(p)==mp.end())
            {
                mp[p]=rank;
                rank++;
            }
        }
        for(int i=0;i<N;i++)
        {
             temp[i]=mp[arr[i]];
        }
        return temp;

    }

};


