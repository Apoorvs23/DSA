#include <iostream>
using namespace std;
class heap
{
public:
	int arr[100]; // we are not using 0th index
	int size;
	heap()
	{
		arr[0]=-1;
		size=0;
	}
	void insert(int val)
	{
		//increase the size of the heap
		size++;
		int index=size;
		arr[size]=val;
		while(index>1)
		{
			int parent=index/2;
			if(arr[parent]<arr[index])
			{
				swap(arr[parent],arr[index]);
				index=parent;
			}
			else
			{
				return;
			}
		}
		
			
	}
	void remove()
		{
			if(size==0) 
			{
				cout<<"Heap is empty, invalid opteration!"<<endl;
				return;
			}
		    arr[1]=arr[size]; //swapping it with last index;
			size--;
			int index=1;
			while(index<size)
			{
				int leftChild=2*index;
				int rightChild=2*index+1;
				if(leftChild<size && arr[leftChild]>arr[index])
				{
					swap(arr[leftChild],arr[index]);
					index=leftChild;
				}
				else if(rightChild<size && arr[rightChild]>arr[index])
				{
					swap(arr[rightChild],arr[index]);
					index=rightChild;
				}
				else
				{
					return;
				}
			}
        }
	void print()
	{
		for(int i=1;i<=size;i++) cout<<arr[i]<<" ";
		cout<<endl;
	}
    //leaf nodes are from n/2+1 to n and all leaf nodes are heap among them, so our work is to jus traverse it from 0 to n/2;
    void heapify(int arr[],int size,int nodeIndex) // the work of heapify is to take the node to its respective address -O(logn)
    {
        //get the largest index where nodeIndex will point
        int largest=nodeIndex;
        int left=2*nodeIndex;
        int right=2*nodeIndex+1;
        if(left<=size && arr[left]>arr[largest]) //which should be greater as we are creating maxHeap
        {
           largest=left;
        }
        if(right<=size && arr[right]>arr[largest]) // if because it should be bigger than both
        {
            largest=right;
        }
        if(largest!=nodeIndex)//largest get updated
        {
            swap(arr[largest],arr[nodeIndex]); //now nodeIndex is largest and point to correct position
            heapify(arr,size,largest); //check for other trees
        }
       

    }
    void heapSort(int arr[],int n)
    {
        while(n>1)
        {
            swap(arr[1],arr[n]);
            heapify(arr,n,1);//heapify first node;
            n--;
        }
    }
};
int main() {
	// your code goes here
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();
	h.remove();
	h.print();
    int arr[]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--)
    {
        h.heapify(arr,n,i);
    }
   for(int i=1;i<=n;i++)
   {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   h.heapSort(arr,n);
     for(int i=1;i<=n;i++)
   {
       cout<<arr[i]<<" ";
   }
	return 0;
}


//heapsort:
// heapsort()
// {
//     build heap using heapify that will go from n/2 to 0
//     //heapSOrt code -swap, heapify 
// }