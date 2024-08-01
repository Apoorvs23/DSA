
//https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> ans;
        for(int lengthOfTheWindow = 1; lengthOfTheWindow<=n; lengthOfTheWindow++)
        {
            // start + remaining Length of Window <= n-1
            // start + (lengthOfTheWindow -1) <= n-1 -> kyonki ek toh start hi hogya
            // start <= n-lengthOfTheWindow
            int maxInWindowSize = INT_MIN;
            for(int start=0; start <= n-lengthOfTheWindow; start++) 
            {
                // now we will traverse window for each element we will find minimum
                int minInWindow = INT_MAX;
                for(int k = start; k < start + lengthOfTheWindow; k++) //traverse till length of the window
                {
                    minInWindow = min(minInWindow,arr[k]);
                }
                maxInWindowSize = max(minInWindow,maxInWindowSize);
            }
            ans.push_back(maxInWindowSize);
            
        }
        return ans;
    }
};