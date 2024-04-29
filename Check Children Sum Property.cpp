
//https://www.geeksforgeeks.org/problems/children-sum-parent/1

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
  int isSumProperty(Node *root)
  {
    if (!root || (!root->left && !root->right)) // If root is NULL or it's a leaf node
        return 1;
    
    int left_data = root->left ? root->left->data : 0; // Check if root->left is NULL
    int right_data = root->right ? root->right->data : 0; // Check if root->right is NULL

    if ((root->data == left_data + right_data) && isSumProperty(root->left) && isSumProperty(root->right))
        return 1;

    return 0;
   }
};