// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1


//Time Complexity: O(M+N), M is the size of the first tree and N is the size of the second tree
//Auxiliary Space: O(H1 + H2), H1 is the height of the first tree and H2 is the height of the second tr

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       if(!root1 && !root2) return {};
       stack<Node*> s1,s2;
       vector<int> vis;
       while(!s1.empty() || !s2.empty() || root1 || root2)
       {
           while(root1)
           {
               s1.push(root1);
               root1=root1->left;
           }
           while(root2)
           {
               s2.push(root2);
               root2=root2->left;
           }
           if(s2.empty() || (!s1.empty() && s1.top()->data<=s2.top()->data))
           {
               vis.push_back(s1.top()->data);
               root1=s1.top()->right; // root1= s1.top()->right
               s1.pop();
           }
           else // confirm here that s2 is not empty
           {
               vis.push_back(s2.top()->data);
               root2=s2.top()->right;
               s2.pop();
           }
       }
       return vis;
       
    }
};