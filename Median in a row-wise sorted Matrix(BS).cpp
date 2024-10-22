// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

// we want to skip some elements as we want to reduce it bloew NxM and other thing it is sorted so we can think og BS

// When 𝑁 N is odd, the median 𝑥 x is the middle element, meaning there are exactly 𝑁 − 1 2 2 N−1 ​ elements smaller than 𝑥 x and one element that equals 𝑥 x. Therefore, the count of elements smaller or equal to 𝑥 x is:

// no.ofelements < = median has to be greater than mid 
// If ‘x’ is the median, the number of elements smaller or equal to ‘x’ will be surely greater than (MXN) // 2 (integer division).

// now find the first element that has >N/2 occurence wiill be mine median
// we are trying to find first occurence of > (nxm/2)

//In short words -> median will be first element which is n/2 + 1

// Complexity Analysis

// Time Complexity: O(log(109)) X O(M(logN)), where M = number of rows in the given matrix, N = number of columns in the given matrix

// Reason: Our search space lies between [0, 109] as the min(matrix) can be 0 and the max(matrix) can be 109. We are applying binary search in this search space and it takes O(log(109)) time complexity. Then we call countSmallEqual() function for every ‘mid’ and this function takes O(M(logN)) time complexity.

// Space Complexity : O(1) as we are not using any extra space


class Solution{   
private:
    int upperBound(vector<int> arr, int x)
    {
        int low = 0;
        int high = arr.size()-1;
        while(low<=high)
        {
            int mid  = (low + high) >> 1;
            if(arr[mid]>x)
                high = mid - 1;
            else
                low = mid +1;
        }
        return low;
    }
    
    int countSmallEqual(vector<vector<int>> matrix , int x)
    {
        int count = 0;
        for(int i = 0; i<matrix.size(); i++) // TC: O(n * LogM) -> go to every row and find upperBound
        {
            count += upperBound(matrix[i],x);
        }
        return count;
    }
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        int  low = INT_MAX, high = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<n; i++) // row wise sorted so get min in 0th colum and max in nth 
        {
            low = min(low,matrix[i][0]);
            high = max(high,matrix[i][m-1]);
        }
        int req = (n*m)/2;
        while(low<=high) // max calue is 2000 so  O log((2000 - 1)) * n LogM -> for each BS you are calling countSmall eqyal
        {
            int mid = (low + high) >> 1;
            int smallEqual = countSmallEqual(matrix,mid);
            if(smallEqual>req)
                high = mid - 1;
            else
                low = mid + 1;
            
        }
        return low;
        
       
    }
}
