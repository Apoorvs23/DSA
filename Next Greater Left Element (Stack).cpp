#include <bits/stdc++.h>
using namespace std;
vector<int> ngl(vector<int> &v)
{
    int n = v.size();
    vector<int> ans (n);
    stack<int> s;
    for(int i = 0;i<2*n;i++)
    {
        while(!s.empty() && s.top()<=v[i%n]) s.pop();
        if(i<n)
        {
            if(!s.empty()) ans[i] = s.top();
            else ans[i] = -1;
        }
         s.push(v[i%n]);
    }
    return ans;
}

int main() {
    vector<int> v = {1,3,2,4};
    vector<int> ans = ngl(v);
    for(auto p:ans) cout<<p<<" ";
}
