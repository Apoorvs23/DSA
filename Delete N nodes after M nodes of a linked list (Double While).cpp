
//https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1
//TC: O(N), SC:(1)



   Node* linkdelete(Node* head, int n, int m) {
       if(!n) return head;
       else if(!head || m==0) return NULL;
       
       Node* temp  = head;
       while(temp)
       {
           int count = 1;
           while(temp && count<m)
           {
               temp = temp->next;
               count++;
           }
           if(!temp) return head;
           count = 0;
           while(temp && temp->next && count<n)
           {
               Node* deleteNode = temp->next;
               delete(deleteNode);
               temp->next = temp->next->next;
               count++;
           }
           if(!temp || !temp->next) return head;
           temp = temp->next;
       }
       
       
       
    }



class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        if(!head) return;
        while(head)
        {
            int skip = M-1;
            while(head && skip--)
            {
                head = head->next;
            }
            int twoDelete = N;
            while(head && head->next && twoDelete--)
            {
                Node* toDelete = head->next;
                head->next = head->next->next;
                delete(toDelete);
            }
            if(head) head = head->next;
        }
    }
};

//
/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

*/
class Solution {
  public:
    void linkdelete(struct Node **head, int n, int m) {
       if(n==0) return;
       else if(m==0)
       {
         *head = NULL;
       }
        Node* curr = *(head);
       while(curr)
       {
           //skip m nodes
            int count = 1;
            while(curr && count<m)
            {
                count++;
                curr = curr->next;
            }
            if(!curr) return;
            //delete n nodes
            count = 0;
            while(curr && curr->next &&  count<n)
            {
                curr->next = curr->next->next;
                count++;
            }
           if(curr) curr = curr->next;
       }
       
    }
};
