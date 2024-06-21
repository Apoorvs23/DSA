
//https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1
//TC: O(N), SC:(1)
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(!head || N==0) return;
        Node* temp = head;
        while(temp)
        {
            //skip M nodes
            for(int i=1;i<M && temp->next ;i++)
            {
                temp = temp->next;
            }
            if(!temp) return;
            for(int i=0;i<N && temp && temp->next;i++)
            {
                temp->next =temp->next->next;
            }
            temp =temp->next;
        }
    }
};


