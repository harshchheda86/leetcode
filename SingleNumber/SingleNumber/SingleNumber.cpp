// SingleNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]

*/

#include <iostream>
#include<vector>
#include <map>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    map<int, bool> appear;
    vector<int> once;

    for (auto num : nums)
    {
        if (!appear.count(num))
        {
            appear[num] = true;
        }
        else
        {
            appear[num] = false;
        }
    }

    for (auto it = appear.begin(); it != appear.end(); it++)
    {
        if (it->second) once.push_back(it->first);
    }

    return once;
}

int main()
{
    std::cout << "Hello World!\n";
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
