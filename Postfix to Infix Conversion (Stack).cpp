
// // https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion//1
// if operand  put in stack
// if opertor, pop last 2 elements from stack and push (A operator B) in stack with brackets

// TC: O(N) + O(N)
// SC: O(N) for stack
class Solution {
  public:
    string postToInfix(string exp) {
      int n = exp.size();
      if(n==0 || n==1) return exp;
      stack<string> s;
      for(auto p:exp) // O(N)
      {
          if( (p>='A' && p<='Z') || (p>='a' && p<='z') || (p>='0' && p<='9')) // (O(1))
          {
              s.push(string(1,p));
          }
          else // operator // O(N) because adding two string is O(N1) + O(N2) 
          {
              string first = s.top();
              s.pop();
              string second = s.top();
              s.pop();
              //string expression = "(" + second + p + first + ")"; // remeber order of second and first
              s.push( "(" + second + p + first + ")");
          
              
          }
      }
      return s.top();
    }
};