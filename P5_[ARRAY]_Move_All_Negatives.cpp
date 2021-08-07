// Move all negative numbers to beginning and positive to end with constant extra space

#include <bits/stdc++.h>
using namespace std;

void two_pointer_approach(int arr[], int size);
void partition(int arr[], int size);

int main()
{
    int arr[] = {-1, 1, 5, 123, -5, 124, 1, 1, -1, -19, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    // two_pointer_approach(arr, size);

    partition(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// Two pointer approach
void two_pointer_approach(int arr[], int size)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        // if left and right are both negative, move the left pointer ahead
        if (arr[left] < 0 && arr[right] < 0)
            left++;
        // if left is positive nad right is negative, then swap the two
        else if (arr[left] > 0 && arr[right] < 0)
        {
            swap(arr[left], arr[right]);
        }
        // if both are positive, move the right pointer towards the left
        else if (arr[left] > 0 && arr[right] > 0)
        {
            right--;
        }
        // else they are in the desired position, simply move the two pointers
        else
        {
            left++;
            right--;
        }
    }
}

// Partitioning

void partition(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int j = start;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}