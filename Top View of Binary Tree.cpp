//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    //in this we wont consider elements that are already present in map with perticular vIndex
    vector<int> topView(Node *root)
    {
        if(!root) return {};
        map<int,int> mp; //vIndex, node->val
        queue<pair<Node*,int>> q; //Node,vIndex
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                Node* top = q.front().first;
                int vIndex = q.front().second;
                q.pop();
                if(mp.find(vIndex)==mp.end())
                {
                    mp[vIndex]=top->data;
                }
                if(top->left) q.push({top->left,vIndex-1});
                if(top->right) q.push({top->right,vIndex+1});
        
            }
        }
        vector<int> vis;
        for(auto p:mp)
        {
            vis.push_back(p.second);
        }
        return vis;
    }

};