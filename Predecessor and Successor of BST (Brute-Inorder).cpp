// It sets pre and suc as predecessor and successor respectively
//https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
//  TC: O(N), SC: O(N)
class Solution
{
    private:
    void inorderUtil(Node* root, vector<Node*> & vis)
    {
        if(!root) return;
        inorderUtil(root->left,vis);
        vis.push_back(root);
        inorderUtil(root->right,vis);
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if(!root) return;
        // Your code goes here
        vector<Node*> inOrder;
        inorderUtil(root,inOrder); // sorted
        for(auto node:inOrder)
        {
            if(node->key<key) pre=node;
            else if(node->key>key)
            {
                suc=node;
                return;
            }
        }
    }
};