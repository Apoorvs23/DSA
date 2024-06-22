//https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

//TC: O(2N)
//SC: O(1)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int arr[3]={0};
        Node* temp = head;
        while(temp)
        {
            if(temp->data==0) arr[0]++;
            else if(temp->data==1) arr[1]++;
            else arr[2]++;
            temp=temp->next;
        }
        temp = head;
        while(temp)
        {
            if(arr[0]>0)
            {
                 temp->data = 0;
                 arr[0]--;
            }
            else if(arr[1]>0)
            {
                 temp->data = 1;
                 arr[1]--;
            }
            else 
            {
                temp->data = 2;
                arr[2]--;
            }
            temp = temp->next;
        }
        return head;
        
    }
};