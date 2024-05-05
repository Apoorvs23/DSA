//https://www.geeksforgeeks.org/problems/largest-bst/1

//TC: O(N), SC:O(1) ignoring recursive stack
class Nodedataue{
    public:
    int minNode,  maxNode,  maxSize;
    Nodedataue(int minNode,int maxNode,int maxSize)
    {
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->maxSize=maxSize;
    }
};

class Solution {
private:
    Nodedataue largestBstHelper(Node* root)
    {
        if(!root) return Nodedataue(INT_MAX,INT_MIN,0); // max is int_min < x will always be true
        Nodedataue left =  largestBstHelper(root->left);
        Nodedataue right = largestBstHelper(root->right);
        //if it is a BST
        if(left.maxNode<root->data && root->data<right.minNode)
        {
            return Nodedataue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1); //giving sabse minimum kya hai or sabse maxmium or root se compare isliye kra hai kyonki maanlo left tree NULL na ho
        }
        //it is not BST - dont include it
        return Nodedataue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize)); // size is like if one tree was bst so we will send the size above 
    }
public:
    int largestBst(Node* root) {
        if(!root) return 0;
        return largestBstHelper(root).maxSize;
    }
};