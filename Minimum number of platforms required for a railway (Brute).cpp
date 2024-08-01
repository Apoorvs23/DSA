
//https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

//TC: O(N2), SC: O(1)

class Solution{
    public:
    //four cases for a train B
    // train B arrives before and departs later
    // train B arriving before train A and departing middle
    // train b arrives in middle and departs later
    // train B arrives and departs in middle
    // train B comes first or in mid and then departs mid or later
    
    
    // two conditions for me:
    // train A baadmein aayi or train B gayi nhi thi
    // train B baadmein aayi or train A gayi nhi thi
    int findPlatform(int arr[], int dep[], int n)
    {
    	int maxPlatforms = 1;
    	for(int i =0;i<n;i++)
    	{
    	    int current=0;
    	    for(int j=0;j<n;j++)
    	    {
    	        if(arr[i] >= arr[j] && dep[j] >= arr[i])
    	        current++;
    	    }
    	    maxPlatforms = max(current,maxPlatforms);
    	}
    	return maxPlatforms;
    }
};

