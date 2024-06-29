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
//TC:O(N^2) -> for each element we may need to empty all stack every time
// N element ke liye N baar empty kra toh N^2
//SC: O(N) auxiliary space
void insert(stack<int> &s , int ele)
{
    if(s.size()==0 || s.top()<=ele) 
    {
        s.push(ele);
        return;
    }
    int val = s.top(); // if this is big lets try to push other inside - matlb yeh last element val toh bada hai toh isko  nikalkr "ele" ko ander dalne ka sochte hai
    s.pop();
    insert(s,ele);
    s.push(val);
    return;
}
void SortedStack :: sort()
{
   //Your code here
   if(s.size()==0 || s.size()==1) return;
   int lastElement = s.top();
   s.pop();
   // now I will ask it to sort remaining elements
   sort();
   //here way say our stack is sorted
   insert(s,lastElement);
   return;
}