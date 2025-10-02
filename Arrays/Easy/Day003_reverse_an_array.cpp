/*
GFG 160 Days Challenge - Day 3: Reverse an Array
------------------------------------------------
You are given an array of integers arr[]. You have to reverse the given array.

Note: Modify the array in place.

Approach:
---------
- Use two pointers:
  * i → start of the array
  * j → end of the array
- Swap arr[i] and arr[j], then move i forward and j backward
- Continue until i >= j

Time Complexity:  O(n)   
Space Complexity: O(1)   
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int> &arr) {
        int i = 0, j = arr.size() - 1;
        
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};

// Example usage
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    
    Solution().reverseArray(arr);

    cout << "Reversed array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
