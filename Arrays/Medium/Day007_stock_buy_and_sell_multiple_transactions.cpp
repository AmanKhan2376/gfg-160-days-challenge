/*
GFG 160 Days Challenge - Day 7 : Stock Buy and Sell – Multiple Transaction Allowed
----------------------------------------------------------
The cost of stock on each day is given in an array price[]. 
Each day you may decide to either buy or sell the stock at price[i]; 
you can even buy and sell the stock on the same day. 
Find the maximum profit that you can get.

Note:
- A stock can only be sold if it has been bought previously.
- Multiple stocks cannot be held on any given day.

Approach:
---------
- This is a greedy problem.
- If price[i] > price[i - 1], we can profit by buying at i - 1 and selling at i.
- Sum all such positive differences to get the maximum profit.
- Equivalent to accumulating all upward movements in the price array.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << "Maximum Profit: " << sol.maximumProfit(prices) << endl; 
    // Output: 865
    return 0;
}
