// ContainsDuplicate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<map>

using namespace std;

/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        if (result.find(nums[i]) != result.end())
        {
            if (abs(i - result[nums[i]] <= k))
                return true;
        }
        result[nums[i]] = i;
    }

    return false;
}

bool containsDuplicate(vector<int>& nums) {
    map<int, bool> result;

    for (auto num : nums)
    {
        if (result.find(num) == result.end())
        {
            result[num] = true;
        }
        else
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> nums = { 1, 2, 3, 4 };
    vector<int> nums2 = { 1, 2, 1, 1 };

    cout << "Contains Duplicate?" << containsDuplicate(nums2) << endl;

    cout << "Contains nearby Duplicate?" << containsNearbyDuplicate(nums, 3) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
