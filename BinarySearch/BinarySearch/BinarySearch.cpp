// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

#define INVALID_INDEX (0xFFFFFFFF)

// Returns the element index of the element to be searched.
uint32_t BinarySearch(vector<uint32_t> nums, uint32_t target, bool &found)
{
    uint32_t size = nums.size();
    uint32_t mid = size >> 1;
    uint32_t left = 0;
    uint32_t right = size - 1;

    while (!found)
    {
        if (target == nums[mid])
        {
            found = true;
            return mid;
        }
        else if (target > nums[mid])
        {
            left = mid;
            mid = mid + ((right - left) >> 1);
        }
        else
        {
            right = mid;
            mid = mid - ((right - left) >> 1);
        }
    }
    return INVALID_INDEX;
}

int main()
{
    vector<uint32_t> nums = {1, 2, 3, 4, 5, 6, 7, 8 };
    uint32_t target = 7;

    bool found = false;

    uint32_t index = BinarySearch(nums, target, found);

    if (found) cout << "Found " << target << "at index " << index << endl;
    else cout << "Not Found !!!" << endl;

    return 0;
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
