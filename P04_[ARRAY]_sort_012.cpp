// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int size);
void sort012DutchFlag(int arr[], int size);

int main()
{
    int arr[] = {0, 1, 1, 2, 0, 2, 2, 2, 0, 0, 0, 1, 1, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    // sort012(arr, size);

    sort012DutchFlag(arr, size);
}

// Counting sort
// This approach works, but not necessarily correct. We're building a string, and not an array.
// If we overwrite the array itself, then the approach would take O(2N) time
void sort012(int arr[], int size)
{
    string zero = "", one = "", two = "";

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            zero += "0";
        else if (arr[i] == 1)
            one += "1";
        else
            two += "2";
    }
    string str = zero + one + two;

    cout << str << endl;
}

// Dutch National Flag Algorithm
// This approach takes O(N) time O(1) space, thus it is more optimized approach
void sort012DutchFlag(int arr[], int size)
{
    int low = 0, mid = 0, high = size - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}