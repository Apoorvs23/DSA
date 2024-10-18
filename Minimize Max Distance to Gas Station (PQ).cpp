
// now we want ot reduce the distance -> placing new gas stations before or after the first and last gas station wont help 
// we have to place in middle then
// to minimize put all gas stations between a and b in equal portions to minimizse teh max distance between them
// Time Complexity: O(nlogn + klogn),  n = size of the given array, k = no. of gas stations to be placed.
// Reason: Insert operation of priority queue takes logn time complexity. O(nlogn) for inserting all the indices with distance values and O(klogn) for placing the gas stations.

// Space Complexity: O(n-1)+O(n-1)
//Reason: The first O(n-1) is for the array to keep track of placed gas stations and the second one is for the priority queue.
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &arr, int k) {
       int n = arr.size();
       // there will be n-1 sections in between of the original array
       vector<int> howMany(n-1,0) ; // 0 means initially 0s are placed
       priority_queue<pair<long double, int>> pq;
       
       for(int i = 0; i<n-1; i++)
       {
           long double diff = arr[i+1] - arr[i];
           pq.push({diff,i});
       }
       
       for(int gasStations = 1; gasStations<=k; gasStations++)
       {
           long double diff = pq.top().first;
           int index = pq.top().second;
           pq.pop();
           //place it in the index and find new sectionLength
           howMany[index]++;
            long double inidiff = arr[index + 1] - arr[index];
            long double newSecLen = inidiff / (long double)(howMany[index] + 1);
            pq.push({newSecLen, index});
           
       }
      return pq.top().first;
    }
};
