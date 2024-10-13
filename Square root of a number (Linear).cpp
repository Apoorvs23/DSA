class Solution {
  public:
    long long int floorSqrt(long long int n) {
       int ans = 1; // minium square root is 1 of 1.
       for(int i = 1;i<=n;i++)
       {
           if(i*i<=n)
            ans = i;
            else
                break;
       }
       return ans;
    }
};
