//https://www.geeksforgeeks.org/problems/shortest-job-first/1

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        int t = 0, waitTime = 0;
        for(auto p:bt)
        {
            waitTime+=t;
            t+=p;
        }
        return waitTime/bt.size();
    }
};
