// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
/*
Time Complexity: O(n) to iterate through every position and insert them in a data structure. O(n log n)  to sort the data structure in ascending order of end time. O(n)  to iterate through the positions and check which meeting can be performed.

Overall : O(n) +O(n log n) + O(n) ~O(n log n)

Space Complexity: O(n)  since we used an additional data structure for storing the start time, end time, and meeting no.*/

class Solution
{
    private:
    struct meeting{
        int start;
        int end;
        int pos;
    };
    private:
    // bool static cmp (struct meeting m1, struct meeting m2)
    // {
    //     if(m1.end<m2.end) return true; // dont swap
    //     else if(m1.end>m2.end) return false; //  swap
    //     else if(m1.pos<m2.pos) return true; // dont swap
    //     return false; //swap
    // }
    bool static cmp(meeting m1, meeting m2)
    {
      if(m1.end == m2.end)
      {
          return m1.pos<m2.pos;
      }
      return m1.end<m2.end;      
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meetings[n];
        // Your code here
        for(int i=0;i<n;i++)
        {
            meetings[i].start=start[i];
            meetings[i].end=end[i];
            meetings[i].pos=i+1;
        }
        sort(meetings,meetings+n,cmp);
        int count=1;
        int timeElapsed=meetings[0].end;
        for(int i=1;i<n;i++)
        {
            if(meetings[i].start>timeElapsed)
            {
                count++;
                timeElapsed=meetings[i].end;
            }
        }
        return count;
        
    }
};

