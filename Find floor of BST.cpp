
//https://www.geeksforgeeks.org/problems/floor-in-bst/1
//TC: O(logn)/Height of tree 
//SC: O(1)
// Function to search a node in BST.
class Solution{

/*
    agar root ka data bada hai toh bhai piche jao left tree mein kum kro value
    else ab root->data chota hai toh ise potential answer maankr right mein or dekho ise bada milsake
*/
public:
    int floor(Node* root, int x) {
        // Code here
        if(!root) return -1;
        int pre=-1;
        while(root)
        {
            if(root->data>x) root=root->left;
            else
            {
                pre=root->data;
                root=root->right;
            }
        }
        return pre;
    }
};