//https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1
class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        int floor = INT_MIN, ceil = INT_MAX;
        for(auto p:arr)
        {
            if(p<x) // ppotential floor
            {
                floor = max(floor,p);
            }
            else if(p>x)
            {
                ceil = min(ceil,p);
            }
            else // p==x
            {
                floor = p;
                ceil = p;
                return {p,p};
            }
        }
        if(floor==INT_MIN) floor = -1;
        if(ceil==INT_MAX) ceil = -1;
        return {floor,ceil};
    }
};
