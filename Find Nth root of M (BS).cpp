//BS on ans 
// if you are lesser than you have to move right like i = 1, so we have to check with i=2, i = 3 and if you are greater move left
// surety -> answer will lie between 1 and m
// ans -> [1,m]
//TC: LogM * LogN
// it will overflow as mid/2^ n will be very much when mid is 10^9

//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
class Solution{
private:
int power(long long x , int n, int m) // ignore the negative vase
{
    long long ans = 1;
    while(n>0)
    {
        if(n%2) // odd
        {
            ans*=x;
            n--;
        }
        else
        {
            x = x*x;
            n/=2;
        }
        if(ans>m || x>m) // because when ans becomes large at n==0, ans mein value update oke check hogi
           return 2;
    }
    if(ans>m) return 2; // when power becomes 0, ans i is holding value greatan m but while loop didnt ran
    if(ans==m) return 1;
    return 0;

}
	public:
	int NthRoot(int n, int m)
	{
	    int l = 1, h = m;
	    int ans = -1;
	    if(n==1) return m;
	    while(l<=h)
	    {
	        int mid = l + (h - l) /2;
	        long long midPowerN = power(mid,n, m);
	        if(midPowerN==1)
	            return mid;
	        else if(midPowerN==0)
	            l = mid+1;
	        else h = mid-1;
	         
	    }
	    return -1;
	}  
};
