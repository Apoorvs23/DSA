// User function template for C++

//TC: O(Nx LogM) -> log base 2
//SC: O(1)

// UpperBound of 1
// LowerBound of 0
// FirstOccurence of 1

// The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.


class Solution {
  private:
        int getLowerBound(vector<int> arr)
        {
            int n = arr.size();
            int l = 0, h = n-1;
            while(l<=h)
            {
                int mid = (l+h) >> 1;
                if(arr[mid]==1) // okay this is answer now go left and look for more
                {
                     h = mid-1;
                }
                else l = mid+1;
            }
            return l;
        }
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int maxOnes = 0;
        int maxIndex = -1;
    
        for(int i =0 ; i<n; i++)
        {
            int countOfOnes = arr[i].size() - getLowerBound(arr[i]);
            if(countOfOnes>maxOnes)
            {
                maxOnes = countOfOnes;
                maxIndex = i;
            }
            
        }
        return maxIndex;
    }
};
