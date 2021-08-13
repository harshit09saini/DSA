// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

// Compile using g++ -> ./a.exe

// Take two pointers - start and end
// start = 0, end = length - 1
// swap elements at start and end
// increase the value of start and decrease the value of end

#include <bits/stdc++.h>
using namespace std;

string reverseWord(string str);

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << reverseWord(s) << endl;
    }
    return 0;
}

// } Driver Code Ends

//User function Template for C++

string reverseWord(string str)
{

    //Your code here

    int start = 0, end = str.length() - 1;
    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }

    return str;
}
