/*
GFG 160 Days Challenge - Day 2: Move All Zeroes to End
------------------------------------------------------
You are given an array arr[] of non-negative integers. 
You have to move all the zeros in the array to the right end while maintaining 
the relative order of the non-zero elements. 

The operation must be performed in place, meaning you should not use extra space 
for another array.

Approach:
---------
- Use two pointers:
  * i → iterates over the array.
  * j → tracks the position to place the next non-zero element.
- Traverse the array:
  * If arr[i] != 0 → swap arr[i] with arr[j], increment j.
  * Otherwise → continue.
- This ensures:
  * All non-zero elements remain in the same order.
  * All zeros shift to the end.

Time Complexity:  O(n)   
Space Complexity: O(1)   
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int i = 0, j = 0;
        int n = arr.size();
        
        while (i < n) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
            i++;
        }
    }
};

// Example usage
int main() {
    vector<int> arr = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    
    Solution().pushZerosToEnd(arr);

    cout << "Array after moving zeros to end: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
