//TC: O(N) using mathematical formula

class Solution{
private:
    void heapify(vector<int> &arr, int size, int index)
    {  
       int left = 2*index + 1;
       int right = 2*index + 2;
       int maxIndex = index;
       if(left<size && arr[left]>arr[maxIndex])
       {
           maxIndex = left;
       }
       if(right<size && arr[right]>arr[maxIndex])
       {
           maxIndex = right;
       }
       if(maxIndex!=index)
       {
           swap(arr[maxIndex],arr[index]);
           heapify(arr,size,maxIndex);
       }
    }
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
     for(int i = N/2; i>=0;i--)
     {
         heapify(arr,N,i);
     }
    }
    
};
