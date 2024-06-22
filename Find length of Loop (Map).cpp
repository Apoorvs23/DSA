
//https://www.geeksforgeeks.org/problems/find-length-of-loop/1

int countNodesinLoop(struct Node *head)
{
   if(!head) return 0;
   unordered_map<Node*,int> mp; // node,index;
   Node* temp = head;
   int index = 0;
   while(temp)
   {
        if(mp.find(temp)!=mp.end())
        {
            return index - mp[temp];
        }
        else mp[temp] = index;
        temp = temp->next;
        index++;
   }
   return 0;
}