//https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

// iteratre from back
// when operand -> put into stack
// if opertor -> get (top1 operator top2) and put into stack

// TC: O(N)
// SC: O(N) -> stack
class Solution {
  public:
    string preToInfix(string str) {
       int n = str.size() -1;
       string ans = "";
       stack<string> s;
       while(n>=0) // O(N) + O(N)
       {
            char p = str[n];
            if( (p>='A' && p<='Z') || (p>='a' && p<='z') || (p>='0' && p<='9')) // (O(1))
            {
                s.push(string(1,p));
            }
            else // Max will run for O(N)
            {
                string top1 = s.top();
                s.pop();
                string top2 = s.top();
                s.pop();
                s.push("("+top1+p+top2+")");
            }
            n--;
       }
       return s.top();
    }
};