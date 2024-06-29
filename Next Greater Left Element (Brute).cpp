#include <bits/stdc++.h>
using namespace std;
vector<int> ngl(vector<int> &v)
{
    int n = v.size();
    vector<int> ans;
    for(int i = 0;i<n;i++)
    {
        //traverse back;
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(v[i]<v[j])
            {
                ans.push_back(v[j]);
                break;
            }
        }
        if(j<0) ans.push_back(-1);
    }
    return ans;
}

int main() {
    vector<int> v = {1,3,2,4};
    vector<int> ans = ngl(v);
    for(auto p:ans) cout<<p<<" ";
}