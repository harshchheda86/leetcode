// BinaryTreePaths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void findPaths(TreeNode* node, string path, vector<string>& paths) {
        if (!node) return;
        if (!path.empty()) {
            path = path + "->";
        }
        path = path + to_string(node->val);
        // If it's a leaf node, add the path to the list
        if (!node->left && !node->right) {
            paths.push_back(path);
        }
        else {
            // Otherwise, continue to explore the left and right subtree
            findPaths(node->left, path, paths);
            findPaths(node->right, path, paths);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root != NULL) {
            findPaths(root, "", paths);
        }
        return paths;
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
