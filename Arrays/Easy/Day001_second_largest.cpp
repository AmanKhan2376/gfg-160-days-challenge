/*
GFG 160 Days Challenge - Day 1: Second Largest
----------------------------------------------
Given an array of positive integers arr[], return the second largest element from the array. 
If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Approach:
---------
- Initialize two variables: first and second to INT_MIN.
- Traverse the array:
    - If current element > first → update second = first, first = current element
    - Else if current element > second and != first → update second
- After traversal:
    - If second remains INT_MIN → return -1 (no second largest element)
    - Else return second

Time Complexity:  O(n)   
Space Complexity: O(1)   
*/

#include <iostream>
#include <climits>
using namespace std;

int getSecondLargest(int *arr, int n) {
    int first = INT_MIN, second = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first)  {
            second = arr[i];
        }
    }
    
    if (second == INT_MIN) {
        return -1;
    }
    
    return second;
}

// Example usage
int main() {
    int arr[] = {10, 5, 20, 20, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = getSecondLargest(arr, n);

    cout << "Second largest element: " << result << endl;

    return 0;
}
