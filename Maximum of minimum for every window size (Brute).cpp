
//https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        if(n==0) return {};
        vector<int> v;
        for(int k=1;k<=n;k++) // size of the window
        {
            int maxx = INT_MIN;
            for(int i=0; i<=n-k ; i++) // it will decide the starting point of window 
            {
                int mini = arr[i];
                for(int j=i;j<i+k;j++)
                {
                    mini = min(mini,arr[j]);
                }
                maxx = max(maxx,mini);
            }
            v.push_back(maxx);
        }
        return v;
    }
};


// class Solution
// {
//     public:
//     //Function to find maximum of minimums of every window size.
//     vector <int> maxOfMin(int arr[], int n)
//     {
//         vector<int> ans;
//         for(int lengthOfTheWindow = 1; lengthOfTheWindow<=n; lengthOfTheWindow++)
//         {
//             // start + remaining Length of Window <= n-1
//             // start + (lengthOfTheWindow -1) <= n-1 -> kyonki ek toh start hi hogya
//             // start <= n-lengthOfTheWindow
//             int maxInWindowSize = INT_MIN;
//             for(int start=0; start <= n-lengthOfTheWindow; start++) 
//             {
//                 // now we will traverse window for each element we will find minimum
//                 int minInWindow = INT_MAX;
//                 for(int k = start; k < start + lengthOfTheWindow; k++) //traverse till length of the window
//                 {
//                     minInWindow = min(minInWindow,arr[k]);
//                 }
//                 maxInWindowSize = max(minInWindow,maxInWindowSize);
//             }
//             ans.push_back(maxInWindowSize);
            
//         }
//         return ans;
//     }
// };
