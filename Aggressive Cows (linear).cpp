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
int AGGRCOW(vector<int> stalls, int cows)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int l = 1; // atleast distance beween two cows can be of 1 unit
    int h = stalls[n-1] - stalls[0];  // max - min
    for(int i = l; i<=h; i++)
    {
        if(!canWePlace(stalls,cows,i))
            return i-1; // this was the last index where we can place
    }
    return -1;
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
