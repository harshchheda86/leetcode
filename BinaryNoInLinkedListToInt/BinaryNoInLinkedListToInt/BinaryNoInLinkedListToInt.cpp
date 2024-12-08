// BinaryNoInLinkedListToInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

*/

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
private:
    uint32_t getListLength(ListNode* head)
    {
        uint32_t Length = 0;

        while (head)
        {
            Length++;
            head = head->next;
        }

        return Length;
    }
public:
    int getDecimalValue(ListNode* head) {
        uint32_t Length = getListLength(head);
        int Value = 0;
        uint32_t i = Length - 1;

        while (head)
        {
            Value += head->val * (0x1 << i);
            head = head->next;
            i--;
        }

        return Value;
    }
};

#include <iostream>

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
