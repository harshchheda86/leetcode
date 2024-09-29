// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// Function to merge 2 sorted arrays
template<typename T>
void Merge(vector<T> input, vector<T> left, vector<T> right)
{
    T left_size = left.size();
    T right_size = right.size();

    uint32_t i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
        {
            input[k++] = left[i++];
        }
        else
        {
            input[k++] = right[j++];
        }
    }

    while (i < left_size)
    {
        input[k++] = left[i++];
    }

    while (j < right_size)
    {
        input[k++] = right[j++];
    }
}

template<typename T>
void MergeSort(vector<T> input)
{
    if (input.size() > 0)
    {
        vector<T> left(input.begin(), input.begin() + input.size() /2);
        MergeSort(left);

        vector<T> right(input.begin() + input.size() / 2, input.end());
        MergeSort(right);

        Merge(input, left, right);
    }
}

int main()
{
    std::cout << "Hello World!\n";
}
