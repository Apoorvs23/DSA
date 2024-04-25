//https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
class Solution {
    //TC - O(N), SC(O(N))
    //perform level order
  public:
    vector <int> bottomView(Node *root) {
        if(!root) return {};
        // Your Code Here
        map<int,int> mp; //vertical Line, node;
        queue<pair<Node*,int>> q;// vertical node,vertical line index
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                Node* top = q.front().first;
                int vIndex = q.front().second;
                mp[vIndex]=top->data;
                q.pop();
                if(top->left) q.push({top->left,vIndex-1});
                if(top->right) q.push({top->right,vIndex+1});
            }
        }
        vector<int> v;
        for(auto p:mp)
        {
            v.push_back(p.second);
        }
        return v;
    }
};