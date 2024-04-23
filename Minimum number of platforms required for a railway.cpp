//https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
    
    /*
    Time Complexity: O(nlogn) Sorting takes O(2nlogn) - 2 arrays and traversal of arrays takes O(2n), 2 arrays so overall time complexity is O(nlogn).

Space complexity: O(1)  (No extra space used).
    */
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1; // second train arrival se dekhna shuru
    	int j=0; // first decendeing departed train
        int maxPlatform=1;
        int currentPlatform=1;
        while(i<n && j<n)
        {
            if(arr[i]<=dep[j]) // train aagayi or pehli wali depart nhi hoyi
            {
                currentPlatform++;
                i++;
            }
            else if(arr[i]>dep[j]) // iska matlb ab yeh train aane se pehle ek jaa chuki hogi usko, platform ko -1 krdo
            {
                currentPlatform--;
                j++; 
            }
            maxPlatform=max(maxPlatform,currentPlatform);
        }
        return maxPlatform;
    }
};

