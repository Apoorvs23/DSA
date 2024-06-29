//https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1
//TC: O(N^2)

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int j;
            for( j = i-1; j>=0; j--)
            {
                if(a[j]<a[i]) 
                {
                    ans[i] = a[j];
                    break;
                }
            }
            if(j<0) ans[i] = -1; // we could not find
        }
        return ans;
    }
};