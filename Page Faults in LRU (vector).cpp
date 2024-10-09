//https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1
//TC: O(N)
//SC: O(N)
class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        vector<int> v;
        int faults = 0;
        for(int i = 0; i<N; i++)
        {
            auto it = find(v.begin(),v.end(),pages[i]);
            if(it==v.end()) // element not present
            {
                if(v.size()==C)
                {
                    v.erase(v.begin());
                }
                v.push_back(pages[i]);
                faults++;
            }
            else
            {
                v.erase(it);
                v.push_back(pages[i]);
            }
        }
        return faults;
    }
};
