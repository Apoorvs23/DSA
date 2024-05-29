// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1


//Time Complexity: O(M+N), M is the size of the first tree and N is the size of the second tree
//Auxiliary Space: O(M + N)
class Solution
{
    private:
    void inorder(Node* root, vector<int> & vis)
    {
        if(!root) return;
        inorder(root->left,vis);
        vis.push_back(root->data);
        inorder(root->right,vis);
    }
    public:
    //Function to return a list of integers denoting the node 
    //dataues of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       if(!root1 && !root2) return {};
       vector<int> b1,b2;
       inorder(root1, b1);
       inorder(root2, b2);
       int n = b1.size();
       int m = b2.size();
       // merge two sorted arrays
      vector<int> mergeV(n+m);
      int i =0, j=0, k=0;
      while(i<n && j<m)
      {
          if(b1[i]<=b2[j]) mergeV[k++]= b1[i++];
          else mergeV[k++] = b2[j++];
      }
      while(i<n) mergeV[k++] = b1[i++];
      while(j<m) mergeV[k++] = b2[j++];
      return mergeV;
    }
};