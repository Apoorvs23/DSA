// while going down increase the node value to maxium so we dont get short
/*
Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because the algorithm traverses each node exactly once, performing constant-time operations at each node.

Space Complexity: O(N) where N is the number of nodes in the Binary Tree.

    In the worst case scenario the tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum height of the tree, resulting in a space complexity of O(N).
    In the optimal case of a balanced tree, the auxiliary space would take up space proportional to O(log2N).
*/
                            
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    // Function to change the values of the nodes
    // based on the sum of its children's values.
    void changeTree(TreeNode* root) 
    {
        if(!root) return;
        int child =0;
        if(root->left) child +=root->left->val;
        if(root->right) child+=root->right->val;
        if(child<root->val) //assign same (root value )to left and right child
        {
            if(root->left) root->left->val = root->val;
            if(root->right) root->right->val = root->val;
        }
        else if(child>=root->val)
        {
            root->val = child;
        }
        changeTree(root->left);
        changeTree(root->right);
int afterModification = (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
        if(root->left || root->right) root->val = afterModification; // only modify if atlease one of child is present else all will become 0.
    }
};


// Function to print the inorder
// traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    // Call the changeTree function
    // to modify the binary tree
    sol.changeTree(root);

    // Print the inorder traversal
    // after modification
    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;

    return 0;
}
                            
                        