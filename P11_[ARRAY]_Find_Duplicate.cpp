// https://leetcode.com/problems/find-the-duplicate-number/
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // This approach is wrong because sorting modifies the array, which does not meet the constraints of the problem.
    // Sorting takes nlogn time complexity
    // Scanning -> O(n)
    int findDuplicate(vector<int> &nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = i + 1;

        while (j < size)
        {
            if (nums[i] == nums[j])
            {
                return nums[i];
            }
            i++;
            j++;
        }
        return -1;
    }

    // Optimized Approach
    // Approach 7: Floyd's Tortoise and Hare (Cycle Detection)
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        Solution obj;
        cout << obj.findDuplicate(nums) << endl;
    }
    return 0;
}
// } Driver Code Ends