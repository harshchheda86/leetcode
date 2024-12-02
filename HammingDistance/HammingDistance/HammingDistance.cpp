// HammingDistance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.



Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
Example 2:

Input: x = 3, y = 1
Output: 1
*/

#include <iostream>

int getBitVal(int value, int bitpos)
{
    return ((value >> bitpos) & 0x1);
}

int hammingDistance(int x, int y) {
    uint32_t HammingDistance = 0;
    int num_bits = sizeof(int) * 8;

    for (int bitpos = 0; bitpos < num_bits; bitpos++)
    {
        int x_val = getBitVal(x, bitpos);
        int y_val = getBitVal(y, bitpos);

        if (x_val != y_val)
        {
            HammingDistance++;
        }
    }

    return HammingDistance;
}

int main()
{
    int dist = hammingDistance(1, 3);
    std::cout << "Hamming Distance: " << dist << std::endl;
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
