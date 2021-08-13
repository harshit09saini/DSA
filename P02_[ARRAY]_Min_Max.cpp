// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
// Also for reference read this: https://afteracademy.com/blog/find-the-minimum-and-maximum-value

// return max and min element of an array

// Impotant -> How to return multiple values from a functionn
// define a struct, use an array, references,

// with struct
// This method makes 2n-1 comparisons

#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int min;
    int max;
};

struct Pair find_min_max(int arr[], int size);
struct Pair min_max_tournament(int arr[], int start, int end);

int main()
{
    int arr[] = {1, 25, 15, 1561, 1, 6, 67, 12};

    int size = sizeof(arr) / sizeof(arr[0]);

    struct Pair min_max_iterative, min_max_recursive;

    min_max_iterative = find_min_max(arr, size);

    cout << "Max: " << min_max_iterative.max << "\nMin: " << min_max_iterative.min << endl;

    min_max_recursive = min_max_tournament(arr, 0, size - 1);

    cout << "Max: " << min_max_recursive.max << "\nMin: " << min_max_recursive.min;
}

struct Pair find_min_max(int arr[], int size)
{
    struct Pair min_max;

    if (size == 1)
    {
        min_max.max = arr[0];
        min_max.min == arr[0];
        return min_max;
    }
    else
    {
        if (arr[0] > arr[1])
        {
            min_max.max = arr[0];
            min_max.min = arr[1];
        }
        else
        {
            min_max.max = arr[1];
            min_max.min = arr[0];
        }
    }
    for (int i = 0; i < size; i++)
    {
        min_max.max = max(min_max.max, arr[i]);
        min_max.min = min(min_max.min, arr[i]);
    }

    return min_max;
}

// Tournament Method i,e, divide the problem into subprobelems until the array size becomes 2, comapre and return.

struct Pair min_max_tournament(int arr[], int start, int end)
{
    struct Pair min_max;

    if (start == end)
    {
        min_max.max = arr[start];
        min_max.min = arr[start];
    }
    else if (end == start + 1)
    { // Two elements only
        if (arr[start] > arr[end])
        {
            min_max.max = arr[start];
            min_max.min = arr[end];
        }
        else
        {
            min_max.max = arr[end];
            min_max.min = arr[start];
        }
    }
    else
    { // More than two elements
        // find mid
        int mid = start + (end - start) / 2; // this prevents overflow than simply doing (start + end) / 2
        struct Pair left = min_max_tournament(arr, start, mid);
        struct Pair right = min_max_tournament(arr, mid + 1, end);
        if (left.max > right.max)
            min_max.max = left.max;
        else
            min_max.max = right.max;
        if (left.min > right.min)
            min_max.min = right.min;
        else
            min_max.min = left.min;
    }
    return min_max;
}