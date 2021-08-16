// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        // code here

        // This approach gives TLE
        for (int i = 0; i < n; i++)
        {
            if (arr1[i] > arr2[0])
            {
                swap(arr1[i], arr2[0]);
                sort(arr2, arr2 + m);
            }
        }
    }

    // Optimized Approach
    int calculateGap(int gap)
    {
        if (gap <= 1)
        {
            return 0;
        }
        // using ceil is unreliable, it gives precision error at times
        return (gap / 2) + (gap % 2);
    }

    void mergeOptimized(int arr1[], int arr2[], int n, int m)
    {
        int gap = n + m;
        int i, j;
        for (gap = calculateGap(gap); gap > 0; gap = calculateGap(gap))
        {
            // Loop for the first array
            for (i = 0; i + gap < n; i++)
            {
                if (arr1[i] > arr1[i + gap])
                {
                    swap(arr1[i], arr1[i + gap]);
                }
            }

            // Loop for both arrays -> Each pointer is in a different array
            for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
            {
                if (arr1[i] > arr2[j])
                {
                    swap(arr1[i], arr2[j]);
                }
            }

            // Loop for the second array
            if (j < m)
            {
                for (j = 0; j + gap < m; j++)
                {
                    if (arr2[j] > arr2[j + gap])
                    {
                        swap(arr2[j], arr2[j + gap]);
                    }
                }
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        // ob.merge(arr1, arr2, n, m);
        ob.mergeOptimized(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends