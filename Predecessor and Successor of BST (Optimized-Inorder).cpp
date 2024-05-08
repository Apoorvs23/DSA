// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
//https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
//  TC: O(N), SC: O(1)
class Solution
{
    private:
    void inorderUtil(Node* root, int key, Node* &pre, Node* &suc) // pass pointers by refernce because maybe in revursive call pointer start pointing to correct but it wont show in main functio because we are chaning the position of pointer where is point to in any function that wont be reflected inn the mainn
    {
        if(!root || suc) return;
        inorderUtil(root->left,key,pre,suc);
        if(root->key<key) pre=root;
        else if(root->key>key && !suc ) // first time
        {
            suc=root;
            return;
        }
      //  vis.push_back(root);
        inorderUtil(root->right,key,pre,suc);
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if(!root) return;
        // Your code goes here
        //vector<Node*> inOrder;
        inorderUtil(root, key,pre, suc); // sorted

    }
};