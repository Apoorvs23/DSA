https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1

// check if page exists -> if exists update the index and return

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_map<int,int> mp; // element, fq;
        int faults = 0;
        for(int i = 0 ; i < N; i++)
        {
            if(mp.find(pages[i])==mp.end())
            {
                mp[pages[i]]  = i;
                faults++;
            }
            else
            {
                mp[pages[i]] = i;
            }
            if(mp.size()>C) //remove least recently use
            {
                int minIndex = INT_MAX;
                int leastRecentlyUsedElement;

                for(auto p:mp)
                {
                   if(minIndex>p.second)
                   {
                       minIndex = p.second;
                       leastRecentlyUsedElement = p.first;
                   }
                }
                mp.erase(leastRecentlyUsedElement);
            }
        }
        return faults;
    }
};
