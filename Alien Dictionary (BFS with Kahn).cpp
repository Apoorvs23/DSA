//https://www.geeksforgeeks.org/problems/alien-dictionary/1
class Solution{
    private:
    vector<int> bfsTopo(vector<int> adj[],int k)
    {
        vector<int> inOrder(k,0);
        queue<int> q;
        vector<int> topoList;
        for(int i=0;i<k;i++)
        {
            for(auto p:adj[i])
            {
                inOrder[p]++;
            }
        }
       for(int i=0;i<k;i++)
       {
           if(inOrder[i]==0)
           {
               q.push(i);
           }
       }
       while(!q.empty())
       {
           int top=q.front();
           q.pop();
           topoList.push_back(top);
           for(auto p:adj[top])
           {
               inOrder[p]--;
               if(inOrder[p]==0) q.push(p);
           }
       }
       return topoList;
    }
    public:
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        string res="";
        for(int i=0;i<n-1;i++) //n-1 because I want pairs
        {
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int i=0;i<len;i++)
            {
                if(s1[i]!=s2[i]) // s1[i] -> s2[i]
                {
                    adj[s1[i]- 'a'].push_back(s2[i]-'a'); //converting them
                    break;// you got the difference
                }
            }
        }
        vector<int> graph= bfsTopo(adj,k);
        for(auto p:graph)
        {
            res=res+char(p+'a');
        }
        return res;
    }
};