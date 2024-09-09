// SortVector.cpp : Sort a vector based on number or ones in its binary representation of its members.
// If the number of ones is equal then sort based on the value itself.
//

#include <iostream>
#include <vector>

using namespace std;

int NoOfOnes(int a)
{
    int size = sizeof(a) << 3;
    int Ones = 0;

    for (int i = 0; i < size; i++)
    {
        if (a & 0x1)
            Ones++;

        a = a >> 1;
    }

    return Ones;
}

bool IsLessThan(int a, int b)
{
    int a_ones = NoOfOnes(a);
    int b_ones = NoOfOnes(b);

    if (a_ones < b_ones)
    {
        return true;
    }
    else if (b_ones > a_ones)
    {
        return false;
    }
    else
    {
        return a < b;
    }

    return false;
}

void SortByNoOfOnes(vector<int> &nums)
{
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            if (IsLessThan(nums[j], nums[i]))
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int main()
{
    vector<int> nums = { 7,3,6,4 };

    SortByNoOfOnes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}
