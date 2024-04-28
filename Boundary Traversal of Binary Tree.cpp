//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// left nodes - execluding leaf
// leaf nodes from left to right (get from inorder)
// right nodes execluding leaf nodes ( reverse them) or take stack and start from root
// TC/SC -  O(N) (auxilary space is O(N))
class Solution {

private:
    bool isLeaf(Node* root)
    {
        return !root->left && !root->right; 
    }
    void leftBoundary(Node* root, vector<int> &vis)
    {
        Node * current = root->left;
        while(current)
        {
            if(!isLeaf(current)) vis.push_back(current->data);
            if(current->left) current=current->left;
            else current=current->right;
        }
    }
    void rightBoundary(Node* root, vector<int> &vis)
    {
        Node* current = root->right;
        vector<int> temp; // because we will reverse it
        while(current)
        {
            if(!isLeaf(current)) temp.push_back(current->data);
            if(current->right) current= current->right;
            else current=current->left;
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            vis.push_back(temp[i]);
        }
    }
    void leaf(Node* root, vector<int> &vis)
    {
        if(!root) return;
        else if(isLeaf(root)) 
        {
            vis.push_back(root->data);
            return;
        }
        if(root->left) leaf(root->left,vis);
        if(root->right) leaf(root->right,vis);
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> vis;
        if(!root) return vis; 
        if(!isLeaf(root)) vis.push_back(root->data); 
        leftBoundary(root,vis); // O(H) - logn
        leaf(root,vis); // O(N)
        rightBoundary(root,vis); // O(H) - logn
        return vis;
    }
};