
//https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
//TC: O(logn)/Height of tree 
//SC: O(1)
//agar root->data chota hai hai toh right jaake bada kro or agar bada hai toh left jaakr just bada dhondho


int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ceil=-1;
    while(root)
    {
        if(root->data<input) root=root->right;
        else
        {
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
    
}