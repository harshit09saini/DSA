// Minimize the Heights II
// Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer.
// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

#include <bits/stdc++.h>
using namespace std;

int minimizeTheHeight(int arr[], int size, int k);

int main()
{
    int arr[] = {1, 5, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << minimizeTheHeight(arr, size, k) << endl;
}

int minimizeTheHeight(int arr[], int size, int k)
{
    sort(arr, arr + size);
    int minn = 0;
    int maxx = 0;
    int res = arr[size - 1] - arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] >= k)
        {
            maxx = max(arr[i - 1] + k, arr[size - 1] - k);
            minn = min(arr[i] - k, arr[0] + k);
            res = min(res, maxx - minn);
        }
    }
    return res;
}