//https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        // Complete this method
        if(!head) return head;
        node* kthNode = head;
        int count = k; //since first node is already taken
 
        node* next = NULL;
        node* prev = NULL;
        while(kthNode && count--) 
        {
            next = kthNode->next;
            kthNode->next = prev;
            prev = kthNode;
            kthNode = next;
        }
        if(kthNode) // after reverse kth node will point to first node of next linklist
        {
            head->next = reverseIt(kthNode,k);
        }
        return prev;
    }
};