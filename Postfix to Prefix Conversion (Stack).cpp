//https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1


// trverse left to right stack
// if operand put into stack
// if operator ->  " operator top 2 top1 " -> put into the stack

// TC: O(2N)
// SC: O(N) -> for stack
class Solution {
  public:
    string postToPre(string str) {
       string ans ="";
       stack<string> s;
       for(auto p:str) // O(N)
       {
           if( (p>='A' && p<='Z') || (p>='a' && p<='z') || (p>='0' && p<='9')) // (O(1))
                s.push(string(1,p));
            else // adding string -> worst can go to O(N)
            {
                string top1 = s.top();
                s.pop();
                string top2 = s.top();
                s.pop();
                s.push(p+top2+top1);
            }
       }
       return s.top();
    }
};