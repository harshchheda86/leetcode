// MajorityElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

#include <iostream>
#include<vector>
#include<map>

using namespace std;

int majorityElement(vector<int>& nums) {
    map<int, int> ElementCount;

    int Elem = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (ElementCount.find(nums[i]) != ElementCount.end())
        {
            ElementCount[nums[i]]++;
        }
        else
        {
            ElementCount.insert({ nums[i], 1 });
        }
    }

    for (auto& elem : ElementCount)
    {
        if (elem.second > (nums.size() >> 1))
        {
            Elem = elem.first;
            break;
        }
    }

    return Elem;
}


#include <algorithm>

// Sort the array and get the element at N/2. Better approach than previous one.
int majorityElement2(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n / 2];
}

int main()
{
    vector<int> nums = { 3,3,1 };
    int result = majorityElement(nums);

    //int result2 = majorityElement2(nums);

    //std::cout << "Majority Element:" << result2 << endl;
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
