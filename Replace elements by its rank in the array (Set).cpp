//https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &v, int N){
        vector<int> rank(N,0); //find all the elements that are smaller than this +1
        for(int i=0;i<N;i++)
        {
            unordered_set<int> s;
            for(int j=0;j<N;j++) if(v[j]<v[i]) s.insert(v[j]);
            rank[i]=s.size()+1;
        }
        return rank;
        
    }

};

