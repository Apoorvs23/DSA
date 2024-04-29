//https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/
//https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property-set-2/

//Time Complexity: O(n^2), Worst case complexity is for a skewed tree such that nodes are in decreasing order from root to leaf.
// as for each node -> we may need to settle up the difference for each node in Skew N nodes * (N times increment function is getting called...)
#include<bits/stdc++.h>
using namespace std;

class node 
{ 
    public:
    int data; 
    node* left; 
    node* right; 
    
    /* Constructor that allocates a new node 
    with the given data and NULL left and right 
    pointers. */
    node(int data)
    {
        this->data = data; 
        this->left = NULL; 
        this->right = NULL;
    }
}; 

void increment(node* root, int diff)
{
    if(!root) return;
    if(root->left)
    {
        root->left->data = root->left->data -diff;
        increment(root->left,diff);
    }
    else if(root->right)
    {
        root->right->data = root->right->data -diff;
        increment(root->right,diff);
    }
}
void convertTree(node* root)
{
    if(!root) return;
    if(!root || (!root->left && !root->right)) return;
    convertTree(root->left);
    convertTree(root->right);  // leftest node in left tree -> kyonki niche se shuru krkr upar jaana hai
    int leftData = (root->left)?root->left->data:0;
    int rightData = (root->right)?root->right->data:0;
    int diff =  (leftData+rightData)- root->data;
    if(diff>0) root->data+=diff;
    else if(diff<0) increment(root,diff);

}
void printInorder(node* node) 
{ 
    if (node == NULL) 
        return; 
    
    /* first recur on left child */
    printInorder(node->left); 
    
    /* then print the data of node */
    cout<<node->data<<" ";
    
    /* now recur on right child */
    printInorder(node->right); 
} 

/* Driver code */
int main() 
{ 
    node *root = new node(50); 
    root->left = new node(7); 
    root->right = new node(2); 
    root->left->left = new node(3); 
    root->left->right = new node(5); 
    root->right->left = new node(1); 
    root->right->right = new node(30); 
    
    cout << "\nInorder traversal before conversion: " << endl; 
    printInorder(root);
    
    convertTree(root); 
    
    cout << "\nInorder traversal after conversion: " << endl; 
    printInorder(root); 
    return 0; 
} 
