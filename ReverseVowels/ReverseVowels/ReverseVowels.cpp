// ReverseVowels.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*

Code


Testcase
Test Result
Test Result
345. Reverse Vowels of a String
Easy
Topics
Companies
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"
*/

#include <iostream>

using namespace std;

bool IsVowel(char c)
{
    return (c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u' ||
        c == 'A' ||
        c == 'E' ||
        c == 'I' ||
        c == 'O' ||
        c == 'U');
}

void Swap(char* left, char* right)
{
    char temp = *left;
    *left = *right;
    *right = temp;
}

string reverseVowels(string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        while (left < right && !IsVowel(s[left]))
            left++;

        while (left < right && !IsVowel(s[right]))
            right--;

        if (left < right)
        {
            Swap(&s[left], &s[right]);
            left++;
            right--;
        }
    }

    return s;
}

int main()
{
    std::cout << reverseVowels("Ui");
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
