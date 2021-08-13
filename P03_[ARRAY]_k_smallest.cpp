// Given an array arr[] and a number K where K is smaller than size of array,
// the task is to find the Kth smallest element in the given array.
// It is given that all array elements are distinct.
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <bits/stdc++.h>
using namespace std;

int kth_largest(int arr[], int k, int size);

int main()
{
    int arr[] = {1, 25, 15, 1561, 1, 6, 67, 12};

    int size = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    int k_largest = kth_largest(arr, k, size);

    cout << "Kth Largest: " << k_largest << endl;
}

int kth_largest(int arr[], int k, int size)
{

    // Sort the array

    sort(arr, arr + size);

    // Return k - 1 element

    return arr[k - 1];
}