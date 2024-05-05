
//https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1
class Solution
{
    private:
    Node* prev=NULL;
    Node* head = NULL;
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        if(!root) return NULL;
        bToDLL(root->left);
        // here we are with last node
        if(!prev) // this is the first element
        {
            head=root;
        }
        else //make two way link
        {
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        bToDLL(root->right); // process for right
        return head;
    }
};
