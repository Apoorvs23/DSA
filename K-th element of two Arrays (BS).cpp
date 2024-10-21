
// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

// in previous question we were doing for even -> two havles -> n/2 and n/2 and for odd 3 and 2
// here we will k and n-k

// Complexity Analysis

// Time Complexity: O(log(min(m, n))), where m and n are the sizes of two given arrays.
// Reason: We are applying binary search on the range [max(0, k-n2), min(k, n1)]. The range length <= min(m, n).

// Space Complexity: O(1), as we are not using any extra space to solve this problem.


class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
       int n1 =arr1.size();
       int n2 = arr2.size();
       if(n1>n2)
        return kthElement(k,arr2,arr1);
       int left = k; //since we will return the ;ast element of the left block
       int low = max(0,k-n2); // manlo k element banane hai or tumhne 0 likha low ko matlb ek bhi nahi uthna arr 1 ka sara uthayo arr2 se but maanlo
       // element hi agar k hi na ho dusre wale me toh arr 1 mein 0 nhi keh sakte na toh uthane padhenge
       // kitne uthane padenge max(0,k-n2) -> jitne kam padh jayenge
       int high = min(k,n1); // loop should go till k
       while(low<=high)
       {
           int mid1 = (low + high) >> 1;
           int mid2 = left - mid1;
           
           int l1 = INT_MIN, l2 = INT_MIN;
           int r1 = INT_MAX, r2 = INT_MAX;
           if(mid1<n1) r1 = arr1[mid1];
           if(mid2<n2) r2 = arr2[mid2];
           if(mid1-1>=0) l1 = arr1[mid1-1];
           if(mid2-1>=0) l2 = arr2[mid2-1];
           
           if(l1<=r2 && l2<=r1)
            return max(l1,l2); // max elementin left array
           else if(l1>r2)
                high = mid1 -1;
            else
                low = mid1+1;
       }
       
       return -1;
       
     
    }
};
