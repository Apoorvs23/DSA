// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

//TC: O(NxM)
//SC: O(1)
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int maxOnes = 0, maxIndex = -1;
        for(int i = 0; i<n ;i++)
        {
            int sum = 0;
            for(int j = 0; j<m; j++)
            {
                sum+=arr[i][j];
            }
            if(maxOnes<sum) // not equalto because we are ;ooking for the first occurence of 1s return first row
            {
                maxOnes = sum;
                maxIndex = i;
            }
        }
        return maxIndex; 
    }
};
