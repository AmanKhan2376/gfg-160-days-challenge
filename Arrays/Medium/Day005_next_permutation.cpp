/*
GFG 160 Days Challenge - Day 5: Next Permutation
------------------------------------------------
Given an array of integers arr[] representing a permutation, implement the next permutation 
that rearranges the numbers into the lexicographically next greater permutation. 
If no such permutation exists, rearrange the numbers into the lowest possible order 
(i.e., sorted in ascending order).

Note: A permutation of an array of integers refers to a specific arrangement of its elements 
in a sequence or linear order.

Approach:
---------
- Traverse from the second last element to the beginning to find the first element arr[i] 
  that is smaller than its next element arr[i+1].
- If such an element is found:
  1. Traverse from the end to find the first element arr[j] greater than arr[i].
  2. Swap arr[i] and arr[j].
  3. Reverse the subarray from i+1 to the end to get the next permutation.
- If no such element is found, the array is in descending order, so reverse the entire array.

Time Complexity:  O(n)   
Space Complexity: O(1)   
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int i = arr.size() - 2;
        while (i >= 0) {
            if (arr[i] < arr[i + 1]) {
                int j = arr.size() - 1;
                while (arr[i] >= arr[j]) j--;
                swap(arr[i], arr[j]);
                reverse(arr.begin() + (i + 1), arr.end());
                return;
            }
            i--;
        }
        reverse(arr.begin(), arr.end());
    }
};

// Example usage
int main() {
    vector<int> arr = {1, 2, 3};
    
    Solution().nextPermutation(arr);

    cout << "Next permutation: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
