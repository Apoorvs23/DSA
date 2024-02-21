//T.C - O(3N) every node is traverse three times, Space - O(3N)
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    if(root==NULL) return {};
    vector<int> pre;
    vector<int> inOrder;
    vector<int> post;
    stack<pair<TreeNode*,int>> s;
    s.push({root,1});
    while(!s.empty())
    {
        TreeNode* top=s.top().first;
        int index=s.top().second;
        s.pop();
        if(index==1) //first time we are visting element (means preorder (root push))
        {
            pre.push_back(top->data);
            s.push({top,2});
            if(top->left) s.push({top->left,1});
        }
        else if(index==2) //2nd time we are visiting - this means left is already visited by us
        {
            inOrder.push_back(top->data);
            s.push({top,3});
            if(top->right) s.push({top->right,1});
        } 
        else //last time we are visitng , left, right are complete
        {
            post.push_back(top->data);
        }
    }
      return {inOrder,pre,post};
}