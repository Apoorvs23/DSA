
// reverse tge infix with brackets
// convert infix to postfix under some controlled condition - anything except ^ and s.top() == p, insert p -> dont delete it like we were deleting before
// reverse that answer

// TC: O(N/2) for reverse  +  //TC: O(N/2) for ending reverse + O(2N) for outer + innter loop
// TC: O(3N)
// SC: O(N) -> for stack
class Solution {
    
  private:
  int priority(char c)
  {
      if(c=='^') return 3;
      else if(c=='*' || c=='/') return 2;
      else if(c=='+' || c=='-') return 1;
      return -1;
  }
 
  void oppositeBracket(string &s)
  {
      for(int i = 0; i<s.size(); i++)
      {
          if(s[i]=='(') s[i]=')';
          else if(s[i]==')') s[i] = '(';
      }
  }
  public:
    string preToInfix(string pre_exp) {
        
       if(pre_exp.size() == 0 || pre_exp.size()==1) return pre_exp;
       stack<char> s;
       reverse(pre_exp.begin(), pre_exp.end()); //TC: O(N)
       oppositeBracket(pre_exp); // convert '('' to ')' and ')' to '(' -  //TC: O(N)
       string ans = "";
       for(auto p:pre_exp)  //TC: O(N)
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
            else // operator
            {
                if(p=='^')
                {
                    while(!s.empty() && priority(s.top()) >= priority(p))
                    {
                        ans+=s.top();
                        s.pop();
                    }
                   
                }
                else
                {
                    while(!s.empty() && priority(s.top()) > priority(p)) // just equal to will be different
                    {
                        ans+=s.top();
                        s.pop();
                    }
                 
                }
                 s.push(p);
            }
            while(!s.empty()) // push all remaining to the stack -> Max Will go till O(N) as total elements
           {
            ans+=s.top();
            s.pop();
           }
           
       }
        reverse(ans.begin(),ans.end());
        return ans;
    }