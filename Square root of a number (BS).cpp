// https://www.geeksforgeeks.org/problems/square-root/0
// 1 2 3, mid = 2
//TC: O(logN)
//SC: O(N)
class Solution {
  public:
    long long int floorSqrt(long long int n) {
       long long l = 1;
       long long h = n;
       long long ans;
       while(l<=h)
       {
           long long mid = l + (h-l)/2;
           if(mid*mid<=n)
           {
               ans = mid; // maybe answer
              l = mid+1;
           }
           else h = mid-1; // eg 14*14> 28 -> 14 wont be answer -> go left
       }
       return ans;
    }
};
