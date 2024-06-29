//https://www.geeksforgeeks.org/problems/help-classmates--141631/1
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> ans(n);
        for(int i = 0; i < n ; i++)
        {
            int j;
            for(j=i+1 ; j<n;j++)
            {
                if(arr[i]>arr[j])
                {
                    ans[i] = arr[j];
                    break;
                }
            }
            if(j==n) ans[i] = -1; // if we could not find it
        }
        return ans;
    } 
};