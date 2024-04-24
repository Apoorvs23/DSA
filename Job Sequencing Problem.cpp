//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

Time Complexity: O(N log N) + O(N*M).

O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.
*/
// the idea is to perform the job with given deadline on last of the day so till between we can perform other jobs which will maxmimize the profit
class Solution 
{
    private:
    bool static comp(struct Job j1, struct Job j2)
    {
        return j1.profit>j2.profit; //decending - swap nhi hona chahe agar yeh condition true hai
    }
    public:
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int maxDays=0;
        for(int i=0;i<n;i++)
        {
            maxDays=max(maxDays,arr[i].dead);
        }
        vector<int> slot(maxDays,-1);
        int jobsCount=0, maxProfit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead-1;j>=0;j--) // ab deadline uthao task ki or piche tak iterate kro
            {
                if(slot[j]==-1) //empty slot
                {
                    slot[j]=arr[i].id;
                    jobsCount++;
                    maxProfit+=arr[i].profit;
                    break;
                }
            }
        }
        return {jobsCount,maxProfit};
    } 
};