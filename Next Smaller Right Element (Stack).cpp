//https://www.geeksforgeeks.org/problems/help-classmates--141631/1
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> ans(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()>=arr[i]) s.pop();
            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();
            s.push(arr[i]);
        }
        return ans;
    } 
};