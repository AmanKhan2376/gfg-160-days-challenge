/*
GFG 160 Days Challenge - Day 6 : Majority Element - More Than n/3
------------------------------------------------
Given an array arr[] consisting of n integers, the task is to find all the 
array elements which occur more than floor(n/3) times.

Note: The returned array of majority elements should be sorted.

Approach:
---------
- At most two elements can appear more than ⌊ n/3 ⌋ times.
- Use the Boyer-Moore Majority Voting Algorithm (extended version).
- Step 1: Find two potential candidates using voting.
- Step 2: Verify their counts in a second pass.
- Step 3: Collect candidates that occur > n/3 times and return sorted.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int cand1 = -1, cand2 = -1;
        int count1 = 0, count2 = 0;
        
        // Step 1: Find potential candidates
        for (int num : arr) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Step 2: Verify the candidates
        count1 = count2 = 0;
        for (int num : arr) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }
        
        // Step 3: Collect valid results
        vector<int> ans;
        if (count1 > n / 3) ans.push_back(cand1);
        if (count2 > n / 3) ans.push_back(cand2);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> arr = {3, 2, 3, 2, 2, 1};
    vector<int> result = sol.findMajority(arr);
    for (int x : result) cout << x << " ";
    cout << endl; // Output: 2
    return 0;
}
