//TC: (LogN)

// https://www.geeksforgeeks.org/problems/binary-search-1587115620/1
class Solution {
private:
    int binarySearchHelper(vector<int> arr, int l, int h ,int k)
    {
        if(l>h)
            return -1;
        int mid = l + (h-l)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]<k)
            return binarySearchHelper(arr,mid+1,h,k);
        return binarySearchHelper(arr,l,mid-1,k);
    }
  public:
      int binarysearch(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        return binarySearchHelper(arr,0,n-1,k);
    }
};
