//https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1
//TC: O(2N+2N)

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int> ans(n);
        stack<int> s;
        for(int i = 0;i<2*n;i++)
        {
            while(!s.empty() && s.top()>=a[i%n]) s.pop(); // it should have first smallest
            if(i<n)
            {
                if(!s.empty()) ans[i] = s.top();
                else ans[i] = -1;
            }
            s.push(a[i%n]);
        }
        return ans;
    }
};