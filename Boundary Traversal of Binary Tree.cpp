//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// left nodes - execluding leaf
// leaf nodes from left to right (get from inorder)
// right nodes execluding leaf nodes ( reverse them) or take stack and start from root
// TC/SC -  O(N) (auxilary space is O(N))
class Solution {
private:
    bool isLeaf(Node* root)
    {
        return root && !root->left && !root->right;
    }
    void left(Node* root , vector<int> & vis)
    {
        if(!root) return;
        Node* curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr)) 
            {
                vis.push_back(curr->data);
                if(curr->left) curr=curr->left;
                else if(curr->right) curr = curr->right;
            }
            else break; // it is leaf node -> stop the iteration
        }
    }
    void right(Node* root , vector<int> & vis)
    {
        if(!root) return;
        Node* curr = root->right;
        vector<int> temp;
        while(curr)
        {
            if(!isLeaf(curr)) 
            {
                temp.push_back(curr->data);
                if(curr->right) curr=curr->right;
                else if(curr->left) curr= curr->left;
            }
            else break;
        }
        for(int i=temp.size()-1;i>=0;i--) vis.push_back(temp[i]);
    }
    void leaf(Node * root, vector<int> &vis)
    {
        if(!root) return;
        else if(isLeaf(root))
        {
             vis.push_back(root->data);
             return;
        }
        leaf(root->left,vis);
        leaf(root->right,vis);
    }
public:
    vector <int> boundary(Node *root)
    {
       if(!root) return {};
       vector<int> vis;
       if(!isLeaf(root)) vis.push_back(root->data);
       left(root,vis);
       leaf(root,vis);
       right(root,vis);
       return vis;
    }
};
