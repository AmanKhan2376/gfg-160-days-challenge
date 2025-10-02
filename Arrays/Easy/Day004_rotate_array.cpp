/*
GFG 160 Days Challenge - Day 4: Rotate Array
--------------------------------------------
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) 
by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Approach:
---------
- Use the reversal algorithm:
  1. Reverse the first d elements.
  2. Reverse the remaining n - d elements.
  3. Reverse the entire array.
- This effectively rotates the array in place without extra space.

Time Complexity:  O(n)   
Space Complexity: O(1)   
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // handle cases where d >= n
        
        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};

// Example usage
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;

    Solution().rotateArr(arr, d);

    cout << "Array after " << d << " left rotations: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
