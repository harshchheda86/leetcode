// BinaryTreeTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void PreOrderTraverse(TreeNode* root, vector<int>& result)
    {
        if (!root)
            return;

        result.push_back(root->val);

        PreOrderTraverse(root->left, result);
        PreOrderTraverse(root->right, result);
    }

    void PostOrderTraverse(TreeNode* root, vector<int>& result)
    {
        if (!root)
            return;

        PostOrderTraverse(root->left, result);
        PostOrderTraverse(root->right, result);

        result.push_back(root->val);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        PreOrderTraverse(root, result);

        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        PostOrderTraverse(root, result);

        return result;
    }
};

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
