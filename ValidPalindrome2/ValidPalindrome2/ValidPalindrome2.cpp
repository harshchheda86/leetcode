// ValidPalindrome2.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
*/

#include <iostream>
using namespace std;

bool IsPalindrome(string s, int left, int right)
{
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool validPalindrome(string s)
{
    if (s.size() <= 1) return true;

    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            return (IsPalindrome(s, left+1, right) || IsPalindrome(s, left, right - 1));
        }
    }
    return true;
}

int main()
{
    std::cout << "IsPalindrome2:" << validPalindrome("abca");
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
