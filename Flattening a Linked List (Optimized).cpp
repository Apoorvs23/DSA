    
//https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1   

//TC: O(N) horizontal nodes * O(M+M) for vertical lengths = O(N* 2M)
//SC: O(1) pr O(N) auxiliary stack recursion space.
Node* merge(Node* l1, Node* l2)
{
    if(!l1)  return l2;
    else if(!l2) return l1;
    Node* res;
    if(l1->data<=l2->data)
    {
        res = l1;
        res->bottom = merge(l1->bottom,l2);
    }
    else
    {
        res = l2;
        res->bottom = merge(l1,l2->bottom);
    }
    return res;
}
Node *flatten(Node *root)
{
   if(!root || !root->next) return root; //single list cannot be flatten
   Node * mergedHead = flatten(root->next);
   return merge(root, mergedHead);
}


