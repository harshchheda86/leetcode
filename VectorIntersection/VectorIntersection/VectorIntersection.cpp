// VectorIntersection.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Given two integer arrays nums1 and nums2, return an array of their
intersection
. Each element in the result must be unique and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    for (int i = 0; i < nums1.size(); i++)
    {
        if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end())
        {
            if (find(result.begin(), result.end(), nums1[i]) == result.end())
            {
                result.push_back(nums1[i]);
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums1 = { 4,9,5 };
    vector<int> nums2 = { 9,4,9,8,4 };

    vector<int> result = intersection(nums1, nums2);

    for (auto res : result)
    {
        cout << res << endl;
    }
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
