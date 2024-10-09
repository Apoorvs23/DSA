//https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1
// TC: O(NxC)
// SC: O(2N)
class Solution{
public:
    int pageFaults(int N, int c, int pages[]){
        // code here
        list<int> l;
        unordered_set<int> s;
        int faults = 0;
        for(int i = 0; i < N ; i++)
        {
            if(s.find(pages[i])==s.end())
            {
                faults++;
                if(l.size()  == c)
                {
                    int lru = l.back();
                    l.pop_back();
                    s.erase(lru);
                }
                s.insert(pages[i]);
                l.push_front(pages[i]);
            }
            else
            {
                l.remove(pages[i]);
                l.push_front(pages[i]);
            }
        }
        return faults;
   
