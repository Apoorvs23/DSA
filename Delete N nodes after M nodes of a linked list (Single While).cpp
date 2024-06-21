
//https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1
//TC: O(N), SC:(1)
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(!head || !N) return;
        int count = 1; // count till M -> when count == M -> delete N nodes
        Node* temp = head;
        while(temp)
        {
            if(count==M) // delete N 
            {
                int deleteN = N;
                while(temp && temp->next && deleteN--)
                {
                    temp->next =temp->next->next;
                }
                count = 0;
            }
            temp = temp->next;
            count++;
        }
        
    }
};
