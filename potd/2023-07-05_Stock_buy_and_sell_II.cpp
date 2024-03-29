/*
The cost of stock on each day is given in an array price[] of size n.
Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day, 
Find the maximum profit which you can get.
Note: You can only hold one stock at a time.

Example 1:
Input:
n = 4
a = {3, 4, 1, 5}
Output: 5
Explanation: We can buy stock on day 1 (at price 3) and sell it on day 2 (at price 4) profit will be 4-3=1, 
We can buy another stock on day 3 (at price 1) and sell it on day 4 (at price 5) profit will be 5-1=4, 
which will give us maximum profit of 5.
*/

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        int start=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>start){
                profit+=prices[i]-start;
                start=prices[i];
            }
            else start=prices[i];
        }
        return profit;
    }
};
