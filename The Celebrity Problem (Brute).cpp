//https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
// TC : O(N^2) + O(N)
// SC: O(2N)
// for celebrity - known by n-1 people
// celebrity should know 0 people
// calculate for all n people
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& v, int n) {
        
       vector<int> knowme(n,0);
       vector<int> iknow(n,0);
       for(int i = 0 ; i<n;i++)
       {
           for(int j = 0 ; j<n; j++)
           {
               if(v[i][j]==1)
               {
                   knowme[j]++; // j is known by someone
                   iknow[i]++;
               }
           }
       }
       for(int i =  0; i<n; i++)
       {
           if(knowme[i]==n-1 && iknow[i]==0) return i;
       }
       return -1;
    }
};