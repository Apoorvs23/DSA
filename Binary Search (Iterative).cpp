//TC: O(LogN) -> height of the tree
//SC: O(1)
//https://www.geeksforgeeks.org/problems/binary-search-1587115620/1

int binarysearch(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int l = 0, h = n-1;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(arr[mid]==k)
                return mid;
            else if(arr[mid]<k)
                l = mid+1;
            else h = mid-1;
        }
        return -1;
    }
