//https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
//TC: O(NLogN) -> N elements inserted in map N*logN
void diagonalHelper(Node* root, map<int,vector<int>> &mp,int levelD)
{
    if(!root) return;
    mp[levelD].push_back(root->data); // TC: (O(N)) for insertion
    diagonalHelper(root->left,mp,levelD+1);
    diagonalHelper(root->right,mp,levelD);
}
vector<int> diagonal(Node *root)
{
    if(!root) return {};
    map<int,vector<int>> mp ; // diagonIndex, vector
    int levelD=0;
    diagonalHelper(root,mp,levelD);
    vector<int> vis;
    for(auto p:mp)
    {
       vis.insert(vis.end(),p.second.begin(),p.second.end());
    //   for(auto c:p.second)
    //   {
    //       vis.push_back(c);
    //   }
    }
    return vis;
   // your code here
}