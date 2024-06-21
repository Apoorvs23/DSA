
//https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1
//TC: O(N), SC:(1)
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

