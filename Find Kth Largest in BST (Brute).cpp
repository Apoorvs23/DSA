// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
//TC: O(N) and SC:O(N)

class Solution
{
    private:
    void inorder(Node*root,vector<int> &vis)
    {
        if(!root) return;
        inorder(root->left,vis);
        vis.push_back(root->data);
        inorder(root->right,vis);
    }
    public:
    int kthLargest(Node *root, int k)
    {
        if(!root) return -1;
        vector<int> vis;
        inorder(root,vis);
        return vis[vis.size()-k]; //n-k
    }
};