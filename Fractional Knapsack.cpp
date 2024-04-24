//  https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

//ALgo - sort by value/weight and then if the weight<knapSack remanining capatiy -> pick entirely else pick portion

// V/W

//Time Complexity: O(n log n + n). O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.
//Space Complexity: O(1), no additional data structure has been used.

class Solution {
  private:
  bool static comp(struct Item it1, struct Item it2)
  {
      double w1 = (double)it1.value/(double)it1.weight;
      double w2 = (double)it2.value/(double)it2.weight;
      return w1>w2;
  }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr,arr+n,comp);
        double maxProfit=0;
        double currentW=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight+currentW<=w) // add the full amount
            {
                maxProfit+=arr[i].value;
                currentW+=arr[i].weight;
            }
            else // break the item and add
            {
                double waitLeft = w-currentW;
                double weightPerUnit = (double)arr[i].value/(double)arr[i].weight;
                double avl = waitLeft*weightPerUnit;
                maxProfit+=avl;
                break;
            }
        }
        return maxProfit;
    }
};
