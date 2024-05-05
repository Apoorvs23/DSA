// It sets pre and suc as predecessor and successor respectively
//https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
//  TC: O(Logn), SC: O(1)
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        if(!root) return;
        while(root)
        {
            if(root->key==key) //find left max and right smallest
            {
                if(root->left)
                {
                    pre=root->left;
                    while(pre->right) pre=pre->right;
                }
                if(root->right)
                {
                    suc=root->right;
                    while(suc->left) suc=suc->left;
                }
                return; // we got our pre and suc
            }
            else if(root->key<key) // toh sirf predecessor milega
            {
                pre=root;
                root=root->right;
            }
            else
            {
                suc=root;
                root=root->left;
            }  
    
        }
        
    }
};