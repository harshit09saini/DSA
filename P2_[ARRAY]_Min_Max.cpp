// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

// return max and min element of an array

// Impotant -> How to return multiple values from a function
// define a struct, use an array, references,

// with struct

#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int min;
    int max;
};

struct Pair find_min_max(int arr[], int size);

int main()
{
    int arr[] = {0, 0, 0, 0, 1, 1, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    struct Pair min_max;

    min_max = find_min_max(arr, size);

    cout << "Max: " << min_max.max << "\nMin: " << min_max.min;
}

struct Pair find_min_max(int arr[], int size)
{
    struct Pair min_max;
    min_max.max = INT_MIN;
    min_max.min = INT_MAX;

    if (size == 1)
    {
        min_max.max = arr[0];
        min_max.min == arr[0];
        return min_max;
    }

    for (int i = 0; i < size; i++)
    {
        min_max.max = max(min_max.max, arr[i]);
        min_max.min = min(min_max.min, arr[i]);
    }

    return min_max;
}