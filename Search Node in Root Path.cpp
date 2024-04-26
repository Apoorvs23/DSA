
//TC/SC - O(N)
private:
bool func(TreeNode* root, TreeNode* search, vector<int> & path)
{   
    if(!root) return false;
    path.push_back(root->val);
    if(root==search)
    {
        return true;
    }
    if(func(root->left,search,path) || func(root->right,search,path))
    {
        return true;
    }
    path.pop_back(); // if we are here this means we didnt found our element so return
    return false;
}
public:
vector<int> SearchPath(TreeNode* root, TreeNode* search)
{
    if(!root) return {};
    vector<int> path;
    func(root,search,path);
    return path;
}