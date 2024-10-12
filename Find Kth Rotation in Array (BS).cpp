/ find the minimum index
//TC: O(LogN)
//SC: O(1)
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
      int n = arr.size();
      int minIndex = -1;
      int minElement = INT_MAX;
      int l = 0, h = n-1;
      while(l<=h)
      {
          if(arr[l]==arr[h])
          {
              if(minElement>arr[l])
              {
                  minElement = arr[l];
                  minIndex = l;
              }
              break;
          }
          int mid = l + (h-l)/2;
          if(arr[l]<=arr[mid]) // sorted
          {
              if(minElement>arr[l])
              {
                  minElement = arr[l];
                  minIndex = l;
              }
              // discard this array
              l  = mid+1;
          }
          else 
          {
              if(minElement>arr[mid])
              {
                  minElement = arr[mid];
                  minIndex = mid;
              }
              // discard this array
              h = mid - 1;
          }
          
      }
      return minIndex;
      
    }
};
