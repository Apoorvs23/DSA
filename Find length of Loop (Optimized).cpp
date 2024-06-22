
//https://www.geeksforgeeks.org/problems/find-length-of-loop/1

int countNodesinLoop(struct Node *head)
{
   if(!head) return 0;
   Node* slow = head;
   Node* fast = head;
   while(fast && fast->next)
   {
       slow = slow->next;
       fast = fast->next->next;
       if(slow==fast)
       {
           int d = 1;
           fast = fast->next;
           while(fast!=slow)
           {
               fast = fast->next;
               d++;
           }
           return d;
       }
   }
   return 0;
}