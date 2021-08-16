// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// Kadane's Algorithm
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int size);

int main()
{
    int arr[] = {1, 2, 3, -2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Max Sum: " << kadane(arr, size) << endl;
}

int kadane(int arr[], int size)
{
    int curr = INT_MIN, maxx = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        curr = max(curr + arr[i], arr[i]);
        maxx = max(curr, maxx);
    }

    return maxx;
}
