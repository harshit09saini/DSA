// KADANE'S ALGORITHM
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int size);
int main()
{
    int arr[] = {-1, -2, -3, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << maxSubarraySum(arr, size) << endl;
}

int maxSubarraySum(int arr[], int size)
{
    // Initialize the current max and a global max
    int current_max = 0, global_max = INT_MIN;

    // O(n) complexity
    for (int i = 0; i < size; i++)
    {
        // if current max + this element is greater than this element, then build the subarray and move forward
        // else, restart the subarray from this element we're currently on
        current_max = max(current_max + arr[i], arr[i]);

        // check if the current max is greater than global max, and update the value of max found till now
        global_max = max(current_max, global_max);
    }

    return global_max;
}