// https://www.geeksforgeeks.org/problems/reverse-a-stack/1

//User function Template for C++
//TC: O(n2)
class Solution{
    void insert(stack<int> &s, int ele)
    {
        if(s.size()==0) 
        {
            s.push(ele);
            return;
        }
        int top = s.top();
        s.pop();
        insert(s,ele);
        s.push(top);
    }
public:
    void Reverse(stack<int> &s){
        if(s.size()==0 || s.size()==1) return;
        int top = s.top();
        s.pop();
        Reverse(s);
        insert(s,top); // it will insert element at last
    }
};