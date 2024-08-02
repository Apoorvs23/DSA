//https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

// add opertors to stack and operands to answer
// if priority(top of stack) < s[i] -> put s[i] in stack
// if  priority(top of stack) > s[i] -> pop it and add it to answer and follow the process
// for "(" -> directly put -> least priority
// if ")" -> take out everything and put till you encounter opening bracket -> dont push any of opening and closing bracket
// pop all remaining elements back to the answers.


// TC: O(N) for outer while loop + O(N) because inner will run for max N elements in all iterations
class Solution {
  private:
  int priority(char c)
  {
      if(c=='^') return 3;
      else if(c=='*' || c=='/') return 2;
      else if(c=='+' || c=='-') return 1;
      return -1;
  }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string str) {
        int n = str.size();
        if(n==0) return "";
        string ans = "";
        stack<char> s;
        for(auto p:str) //TC: (N)
        {
            // if p is operand -> directly push to answer
            if( (p>='A' && p<='Z') || (p>='a' && p<='z') || (p>='0' && p<='9'))
               ans+=p;
            //( -> directly push
            else if (p=='(') s.push(p);
            // ) ->  pop all till you get ()
            else if(p==')')
            {
                while(!s.empty () && s.top()!='(') 
                {
                    ans+=s.top();
                    s.pop();
                }
                if(!s.empty()) s.pop();
            }
            // operator
            else
            {
                // take out all greater priority things and put to answer
                while(!s.empty() && priority(s.top())>= priority(p))  // Max will go till O(N)
                {
                    ans+=s.top();
                    s.pop();
                }
                s.push(p);
            }
        }
        while(!s.empty()) // push all remaining to the stack -> Max Will go till O(N) as total elements
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
        


    }