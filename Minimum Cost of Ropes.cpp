
//https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long v[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> q;
        for(long long i=0;i<n;i++)
        {
            q.push(v[i]); // nlogn
        }
        long long minCost=0;
        while(q.size()>1) //n-1 times
        {
            long long first=q.top();
            q.pop();
            long long second=q.top();
            q.pop();
            minCost+=(first+second);
            q.push(first+second);
        }
        return minCost;
    }
    //T.C. = nlogn
};
