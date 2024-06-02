    
//https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1   
//TC: O(NxM) where N is size of first list and M is inner bottom list + NxM Log NxM for sorting + O(NxM) for creating LL
//TC: 2*O(NxM) + NxM Log NxM
// SC: O(NxM) -> 2 * O(NxM), first for vector and second for new LL.
Node* createLL(vector<int> &vis)
{
    if(!vis.size()) return NULL;
    Node* head = new Node(-1);
    Node* temp = head;
    for(auto p:vis)
    {
        // Node* curr = new Node(p);
        // temp->bottom = curr;
        // temp = temp->bottom;
        temp->bottom = new Node(p);
        temp=temp->bottom;
    }
    return head->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(!root) return NULL;
   vector<int> vis;
   Node* temp = root;
   while(temp) // get all elements in array
   {
       vis.push_back(temp->data);
       Node* down = temp->bottom;
       while(down)
       {
           vis.push_back(down->data);
           down=down->bottom;
       }
       temp=temp->next;
   }
   sort(vis.begin(),vis.end());
   return createLL(vis);;
   
}

