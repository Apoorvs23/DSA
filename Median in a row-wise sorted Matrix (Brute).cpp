//https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// total elements will be always odd as R and C is odd
//TC: O(N*M) + O(NxM * log(NxM)) _> for building + sorting
//SC: O(N*M)
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here  
        vector<int> vis;
        for(int i =0; i<R; i++)
        {
            for(int j = 0; j<C;j++)
            {
                vis.push_back(matrix[i][j]);
            }
        }
        sort(vis.begin(),vis.end());
        return vis[(R*C - 1)/2];
    }
};
