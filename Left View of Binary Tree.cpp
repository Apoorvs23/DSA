    void ultaPre(Node* root, int level, vector<int> &vis)
    {
        if(!root) return;
        if(level==vis.size()) // this is first element
        {
            vis.push_back(root->data);
        }
        ultaPre(root->left,level+1,vis);
        ultaPre(root->right,level+1,vis);
        
    }
vector<int> leftView(Node *root)
{
    if(!root) return {};
        vector<int> vis;
        int level=0;
        ultaPre(root, level,vis);
        return vis;
}
