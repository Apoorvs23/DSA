void traverse(TreeNode* root, vector<int> &pre,vector<int> &ino, vector<int> &post )
{
    if(!root) return;
    pre.push_back(root->data);
    traverse(root->left,pre,ino,post);
    ino.push_back(root->data);
    traverse(root->right,pre,ino,post);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    if(!root) return {};
    vector<int> pre,ino,post;
    traverse(root,pre,ino,post);    
    return {ino,pre,post};
}