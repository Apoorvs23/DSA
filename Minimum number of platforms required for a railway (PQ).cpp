
//https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	priority_queue<int,vector<int>, greater<int>> pq;
    	vector<pair<int,int>> v;
    	for(int i=0;i<n;i++)
    	{
    	    v.push_back({arr[i],dep[i]});
    	}
    	sort(v.begin(),v.end());
    	for(int i=0;i<n;i++)
    	{
    	    pq.push(v[i].second);
    	    if(pq.top()<v[i].first) pq.pop(); // if train already left - remove lowest departure time
    	}
    	return pq.size();
    	
    }
};