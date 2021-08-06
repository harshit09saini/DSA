// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int size);

int main()
{
    int arr[] = {0, 1, 1, 2, 0, 2, 2, 2, 0, 0, 0, 1, 1, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, size);
}

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