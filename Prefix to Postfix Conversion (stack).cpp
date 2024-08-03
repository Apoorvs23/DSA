// start from back
// if operand -> add to the stack
// if operator -> " top 1 top 2 operator "

// TC: O(2N) -> for traversing + ( string 1 + string 2 can go to O(N) )
// SC: O(N) for stack
class Solution {
  public:
    string preToPost(string str) {
        int n = str.size()-1;
        stack<string> s;
        while(n>=0)
        {
            char p = str[n];
            if( (p>='A' && p<='Z') || (p>='a' && p<='z') || (p>='0' && p<='9'))
                s.push(string(1,p));
            else
            {
                string top1 = s.top();
                s.pop();
                string top2 = s.top();
                s.pop();
                s.push(top1+top2+p);
            }
            n--;
        }
        return s.top();
    }
};