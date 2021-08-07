// Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.
// Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union.
// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {
        vector<int> v;

        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (a[i] == b[j])
            {
                if (v.size() > 0 && v[v.size() - 1] != a[i])
                    v.push_back(a[i]);
                else if (v.size() == 0)
                {
                    v.push_back(a[i]);
                }
                i++;
                j++;
            }
            else if (a[i] < b[j])
            {
                if (v.size() > 0 && v[v.size() - 1] != a[i])
                {
                    v.push_back(a[i]);
                }
                else if (v.size() == 0)
                {
                    v.push_back(a[i]);
                }
                i++;
            }
            else
            {
                if (v.size() > 0 && v[v.size() - 1] != b[j])
                {
                    v.push_back(b[j]);
                }
                else if (v.size() == 0)
                {
                    v.push_back(b[j]);
                }
                j++;
            }
        }

        while (i < n)
        {
            if (v[v.size() - 1] != a[i])
                v.push_back(a[i]);
            i++;
        }

        while (j < m)
        {
            if (v[v.size() - 1] != b[j])
            {
                v.push_back(b[j]);
            }
            j++;
        }

        return v.size();
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.doUnion(a, n, b, m) << endl;
    }
    return 0;
}