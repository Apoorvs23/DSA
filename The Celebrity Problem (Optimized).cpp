//https://www.geeksforgeeks.org/problems/the-celebrity-problem/1


// max celebrities - 1 (because agar 2 hoye toh known by all wali baat galat)
// min celebrities - 0
// celebrity exists in 0 to 1
// diagonol will be always 0 since we cannot say i know myself
// row reprsents whom I know
// col represents who knoe me
// all row should be 0 as celebrity dont know anyone
// all col should be 1 leaving diagonal 

//TC: O(2N)
//SC : O(N)
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& v, int n) {
       int top = 0;
       int bottom = n-1;
       while(top<bottom)
       {
           if(v[top][bottom]==1) top++; // position top knows the person at position bottom, Since a celebrity should know no one, top cannot be a celebrity.
           else  bottom--; //Since a celebrity should be known by everyone, bottom cannot be a celebrity.
       }
       if(top>bottom) return -1;
       for(int j = 0; j<n;j++) // top==down
       {
           if(j==top) // diagnol
            continue;
           if(v[top][j]==0 && v[j][top]==1) continue;
           else return -1;
       }
       return top;
    }
};