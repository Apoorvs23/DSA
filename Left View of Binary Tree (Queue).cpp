
//https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
  if(!root) return {};
        queue<Node*> q;
        vector<int> leftView;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            leftView.push_back(q.front()->data);
            while(n--)
            {
                Node * top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                
            }
        }
        return leftView;
}