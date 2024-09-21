// SummaryRanges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<string>
using namespace std;

vector<vector<int>> GetIntRanges(vector<int>& nums)
{
    vector<vector<int>> int_ranges;
    vector<int> range;

    if (!nums.size()) return int_ranges; // Base condition

    int prev = nums[0];
    range.push_back(prev);

    for (uint32_t i = 1; i < nums.size(); i++)
    {
        if (prev + 1 == nums[i])
        {
            range.push_back(nums[i]);
        }
        else
        {
            int_ranges.push_back(range);
            range.clear();
            range.push_back(nums[i]);
        }

        prev = nums[i];
    }

    int_ranges.push_back(range);

    return int_ranges;
}

string GenerateStringRange(const vector<int>& nums)
{
    string range;

    range += to_string(nums[0]);

    if (nums.size() > 1)
    {
        range += "->";
        range += to_string(nums[nums.size() - 1]);
    }

    return range;
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    vector<vector<int>> int_ranges = GetIntRanges(nums);

    for (auto int_range : int_ranges)
    {
        ranges.push_back(GenerateStringRange(int_range));
    }

    return ranges;
}

int main()
{
    std::cout << "Hello World!\n";
    vector<int> nums = { 0,1,2,4,5,7};
    vector<int> nums2 = {0,2,3,4,6,8,9};
    vector<string> ranges = summaryRanges(nums2);

    for (auto range : ranges)
    {
        std::cout << range << std::endl;
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
