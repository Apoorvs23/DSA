// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
//TC: O(N) and SC:O(1)

class Solution
{
    private:
    void inorder(Node*root,int k, int &count, int &kLargest)
    {
        if(!root || count>k) return;
        inorder(root->right,k,count,kLargest);
        count++;
        if(count==k)
        {
            kLargest=root->data;
            return;
        }
        inorder(root->left,k,count,kLargest);
    }
    public:
    int kthLargest(Node *root, int k)
    {
        if(!root) return -1;
        //vector<int> vis;
        int kLargest=-1;
        int count=0;
        inorder(root,k,count, kLargest);
        return kLargest;
    }
};