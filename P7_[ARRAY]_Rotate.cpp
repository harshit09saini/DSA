// Given an array, rotate the array by one position in clock-wise direction.
// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

#include <bits/stdc++.h>
using namespace std;

void rotateByOne(int arr[], int n)
{
    int last = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = last;
}

void rotateByk(int arr[], int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        rotateByOne(arr, n);
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    //code
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        // rotateByOne(arr, N);
        // printArr(arr, N);
        rotateByk(arr, N, 3);
        printArr(arr, N);
    }
    return 0;
}