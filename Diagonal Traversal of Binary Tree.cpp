//https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
//TC/SC: O(N)
vector<int> diagonal(Node *root)
{
   // your code here
   if(!root) return {};
   queue<Node*> q;
   vector<int> vis;
   q.push(root);
   while(!q.empty())
   {
       Node* top = q.front();
       q.pop();
       while(top)
       {
          vis.push_back(top->data);
          if(top->left) q.push(top->left);
          top=top->right;
       }
   }
   return vis;
}