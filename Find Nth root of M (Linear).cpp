//TC: O(N)
//SC: O(1)
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int ans = -1;
	   for(int i = 1; i<=m;i++)
	   {
	       int  val = 1;
	       for(int j = 0; j<n; j++) // this means i*i*i , if nth root is 3, or n=3;
	       {
	           val*=i;
	       }
	       
	       if(val==m)
	            ans = i; // potential answer
	       if(val>m)
	            break;
	   }
	   return ans;
	}  
};
