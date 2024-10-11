//https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
//TC: O(2LogN)
//SC: O(1)
class Solution{
private:
   int getFirstOccurence(int arr[], int target, int  n)
   {
        int l = 0, h=n-1;
        int first = -1;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(arr[mid]==target)
            {
                first = mid; // move left to find more targets
                h = mid-1;
            }
            else if(arr[mid]<target) l = mid+1;
            else h = mid-1;
        }
        return first;
        
   }
    int getLastOccurence(int arr[], int target, int  n)
   {
        int l = 0, h=n-1;
        int last = -1;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(arr[mid]==target)
            {
                last = mid; // move right to find more targets
               l = mid+1;
            }
            else if(arr[mid]<target) l = mid+1;
            else h = mid-1;
        }
        return last;
        
   }
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
        int firstOccurence = getFirstOccurence(nums,target,n);
        if(firstOccurence==-1) return 0; // if first occurence is not there -> there wont be last occurence (lets save logN time by not calling lastOccurence function)
        int lastOccurence = getLastOccurence(nums,target,n);
        return lastOccurence - firstOccurence + 1;
	}
};
