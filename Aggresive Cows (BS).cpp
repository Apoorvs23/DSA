//TC: O( NlogN + O(Log (h-l+1) *O(N)
//SC: O(1)
#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> stalls, int cows, int distance)
{
    int cowsCount = 1;
    int last = stalls[0]; // the first cow placed at first, since from left the distance is covered and we want to be greedily put all the cows
    for(auto p: stalls)
    {
        int dis = p - last;
        if(dis>=distance)
        {
            cowsCount++;
            last = p;
        }
        if(cowsCount==cows)
            return true;
    }
    return false;
}
// when we started the low was on possible point and high was on impossible
// after BS -> they will be on opposite polarity
int AGGRCOW(vector<int> stalls, int cows)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
  // you can shorten the l by finding the minimum consequtive distance between two cows and put l = that value
    int l = 1; // atleast distance beween two cows can be of 1 unit
    int h = stalls[n-1] - stalls[0];  // max - min
    //int ans = -1;
    while(l<=h)
    {
       int mid = l + (h-l)/2 ; // mid is distance
       if(canWePlace(stalls,cows,mid))   
       {
          // ans = mid; // now this possible search in right to get max distance where it is possible to place
           l = mid+1;
       }
       else // everything on the right will not be possible
       {
           h = mid -1;
       }
    }
   // return ans;
   return h;
    
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int> vis(n);
        for(int i = 0; i<n; i++)
        {
            cin>>vis[i];
        }
        cout<< AGGRCOW(vis,c) <<endl;
    }
}
