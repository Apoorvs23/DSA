//https://www.geeksforgeeks.org/problems/sort-a-stack/1

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
// take a temp stack
// get top element of s stack
// pop elemnt of temp stack till it is empty or temp.top() < s.top and put in s


// Time Complexity: O(n2) where n is the total number of integers in the given stack.
// Auxiliary Space: O(n)
void SortedStack :: sort()
{
   if(s.size()==0 || s.size()==1) return;
   stack<int> tempStack;
   while(!s.empty())
   {
       int top = s.top();
       s.pop();
       while(!tempStack.empty() && tempStack.top()>top)
       {
           s.push(tempStack.top());
           tempStack.pop();
       }
       tempStack.push(top);
   }
   s = tempStack;
   
}