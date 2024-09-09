// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include <vector>

int main()
{
    std::shared_ptr<List<uint32_t>> list1 = std::make_shared<List<uint32_t>>();
    std::shared_ptr<List<float>> list2 = std::make_shared<List<float>>();

    std::vector<Node<uint32_t>> nodes1 = { Node<uint32_t>(2), Node<uint32_t>(6), Node<uint32_t>(3), Node<uint32_t>(0), Node<uint32_t>(8), };
    std::vector<Node<float>> nodes2 = { Node<float>(2.2), Node<float>(6.6), Node<float>(3.3), Node<float>(0.0), Node<float>(8.8), };

    for (uint32_t i = 0; i < nodes1.size(); i++)
    {
        list1->InsertAtTail(&nodes1[i]);
        list2->InsertAtHead(&nodes2[i]);
    }

    std::cout << "list1:" << std::endl;
    list1->PrintList();

    std::cout << "list2:" << std::endl;
    list2->PrintList();
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
