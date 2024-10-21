// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

// Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
// Reason: We traverse through both arrays linearly.

// Space Complexity: O(1), as we are not using any extra space to solve this problem.
  
class Solution {
  public:
    int kthElement(int K, vector<int>& arr1, vector<int>& arr2) {
       int n1 =arr1.size();
       int n2 = arr2.size();
       int n = n1+n2;
       int i = 0, j = 0, k = 0;
       while(i<n1 && j<n2)
       {
           if(arr1[i]<=arr2[j])
           {
               k++;
               if(k==K)
                    return arr1[i];
               i++;
           }
           else
           {
               k++;
               if(k==K)
                return arr2[j];
               j++;
           }
       }
       while(i<n1)
       {
           
               k++;
               if(k==K)
                    return arr1[i];
               i++;
       }
       while(j<n2)
       {
               k++;
               if(k==K)
                return arr2[j];
               j++;
       }
       return -1;
     
    }
};
