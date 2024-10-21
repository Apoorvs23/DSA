// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We traverse through both arrays linearly.

// Space Complexity: O(m+n), where m and n are the sizes of the given arrays.

// Reason: We are using an extra array of size (m+n) to solve this problem
  
class Solution {
  public:
    int kthElement(int K, vector<int>& nums1, vector<int>& nums2) {
     int n = nums1.size();
        int m = nums2.size();
        vector<int>  mergeV(n+m);
        int i = 0, j = 0, k = 0;
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
                mergeV[k++] = nums1[i++];
            else
                mergeV[k++] = nums2[j++];
        }
        while(i<n)
            mergeV[k++] = nums1[i++];
        while(j<m)
             mergeV[k++] = nums2[j++];
        
        return mergeV[K-1];
    }
};
