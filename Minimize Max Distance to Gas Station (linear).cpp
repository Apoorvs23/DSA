// https://geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1
// now we want ot reduce the distance -> placing new gas stations before or after the first and last gas station wont help 
// we have to place in middle then
// to minimize put all gas stations between a and b in equal portions to minimizse teh max distance between them
// Time Complexity: O(k*n) + O(n), n = size of the given array, k = no. of gas stations to be placed.
// Reason: O(k*n) to insert k gas stations between the existing stations with maximum distance. Another O(n) for finding the answer i.e. the maximum distance.

// Space Complexity: O(n-1) as we are using an array to keep track of placed gas stations

class Solution {
  public:
    double findSmallestMaxDist(vector<int> &arr, int k) {
       int n = arr.size();
       // there will be n-1 sections in between of the original array
       vector<int> howMany(n-1,0) ; // 0 means initially 0s are placed
       for(int gasStations = 1; gasStations<=k; gasStations++)
       {
           long double maxSectionLength = 0;
           int maxIndex = -1;
           for(int i = 0; i<n-1;i++) // each section
           {
               long double diff = arr[i+1] - arr[i];
               long double sectionLength = (double) diff/(double)((howMany[i]+1)); // +1 because it will divde section in x+1, eg. 2 gas stations will device a block in 3 sections
               if(maxSectionLength<sectionLength)
               {
                   maxSectionLength = sectionLength;
                   maxIndex = i; // matlab naya pump I ke baad daalna
               }
           }
           howMany[maxIndex]++;
       }
       long double maxAns = 0;
       for(int i = 0;i <n-1; i++)
       {
          long double diff = arr[i+1] - arr[i];
          long double sectionLength = (double) diff/(double)((howMany[i]+1)); // +1 because it will divde section in x+1, eg. 2 gas stations will device a block in 3 sections
          maxAns = max(maxAns, sectionLength);
           
       }  
       return maxAns;
    }
}
