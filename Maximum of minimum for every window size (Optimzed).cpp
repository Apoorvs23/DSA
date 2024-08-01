
//https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
// find nsl and find nsr
// create a vector window of length total no. of windows
// ab har element ke liye max length nikalo jismein woh min hai
// fir uss length ke liye window[len] mein max daldo
// because a larger window size can encompass the smaller window, and thus its minimum value can serve as an upper bound for the smaller window sizes.
class Solution
{
    private:
    vector<int> getNSL (int arr[], int n)
    {
        vector<int> v(n,-1);
        stack<int> s;
        for(int i = 0; i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(!s.empty()) v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    vector<int> getNSR (int arr[], int n)
    {
        vector<int> v(n,n);
        stack<int> s;
        for(int i = n-1; i>=0 ;i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(!s.empty()) v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
       vector<int> windowLength(n+1,0); // it will contain max element for each length
       vector<int> nsl = getNSL(arr,n);
       vector<int> nsr = getNSR(arr,n);
       for(int i = 0; i<n;i++)
       {
           int len = nsr[i]  - nsl[i] -1;
           windowLength[len] = max(windowLength[len],arr[i]);
       }
       for(int  i = n-1; i>=0 ; i--)
       {
           windowLength[i] = max(windowLength[i], windowLength[i+1]);
       }
       windowLength.erase(windowLength.begin());
       return windowLength;
    }
};