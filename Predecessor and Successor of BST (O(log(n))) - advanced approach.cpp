// It sets pre and suc as predecessor and successor respectively
//https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
//  TC: O(Logn), SC: O(1)
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    private:
    /*
        agar root->key  bada hai predessor setoh predessor nhi milega toh left mein jao kum kro or agar chota hai toh isko potential maankr right mein jao
    */
    void preHelper(Node* root,Node* &pre,int key) //go to left tree pick rightest
    {
        if(!root) return;
        while(root)
        {
            if(root->key>=key)
            {
               root=root->left;
            }
            else
            {
                pre=root;
                root=root->right;
            }
        }
    }
    /*
     shuru kro root se or dekho agar root->key chota hai key se toh sucessor toh nhi milega toh right jao
     pr agar root->key bada hai toh yeh ek potential successor hai toh isko rkhkr succ mein left mein chalte hai ki ise chota pr key se bada or koi mil jaye
    */
    void sucHelper(Node* root,Node* &suc,int key)
    {
        if(!root) return;
        while(root)
        {
            if(root->key<=key) root=root->right;
            else 
            {
                suc=root;
                root=root->left;
            }
        }
    }
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
       if(!root) return;
        preHelper(root,pre,key);
        sucHelper(root,suc,key);
    }

};