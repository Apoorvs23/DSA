//https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// the low will be max in arr[] , this means one can hold atleast any of the books given and high will that a single student holds all book
// now start from this and check 4 students can get all 5 books or not -> if they cannot increase capacity
// we want everyone can take 1 book and all students will get all the books 
//range  - high
//TC: O(N) + O(Log(high-low+1) * O(N) )
//SC: O(1)
class Solution {
  private:
  void getMaxAndSum(int arr[], int n,  int &maxElement, int &sum)
  {
      for(int i =0; i<n;i++)
      {
          maxElement = max(maxElement,arr[i]);
          sum+=arr[i];
      }
  }
  int allocate(int arr[], int n , int pages)
  {
      int student = 1; // student number 1
      long long pagesStudent = 0; //pages student holding
      for(int i = 0; i <n; i++)
      {
          if(pagesStudent+arr[i]<=pages)
          {
              pagesStudent+=arr[i];
          }
          else
          {
              student++;
              pagesStudent = arr[i];
          }
      }
      return student; // total student required for all the books
      
      
  }
  // available m students, usmeinn kitne bhi utha sakte ho 
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(n<m) //books less students more
            return -1;
        int l = 0, h = 0;  // l says you require atleat l pages sto hold any of the books in array, h will be worst that one can hold all the books (its is worst because we want to give minimum as anaswer)
        getMaxAndSum(arr,n, l ,h);
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(allocate(arr,n,mid)<=m)
            {
                 h  = mid -1;
            }
            else
                l = mid+1;
        }
        return l; // we started with l which was not possible, h which was possible, so opposite polarityy
        // l will end at 71 (possible), high = l-1 (70) -> not possible
         
    }
};
