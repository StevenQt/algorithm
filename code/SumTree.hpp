#pragma once

#include <string>
#include <vector>
#include <deque>

using namespace std;

#include <iostream>

#ifdef TEST_UNIT
void printTree(TreeNode* node)
{
    if (node != NULL)
    {
        std::cout << node->val << " ";
        printTree(node->left);
        printTree(node->right);
    }
}

int main(int argc, char* argv[])
{
    TreeNode root(4);
    TreeNode node2(9);
    TreeNode node3(0);
    TreeNode node4(5);
    TreeNode node5(1);


    root.left = &node2;
    root.right = &node3;

    node2.left = &node4;
    node2.right = &node5;

    printTree(&root);
    std::cout << std::endl;

    int sum = 0;
    int ans = 0;
    DFS(&root, sum, ans);
    std::cout << ans << std::endl;

    getchar();
    return 0;
}
#endif  

/**
* Definition for a binary tree node.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void DFS(TreeNode* root, int sum, int& ans) 
{
    if (root == NULL)
        return;

    sum = sum * 10 + root->val;
    if (root->left) DFS(root->left, sum, ans);
    if (root->right) DFS(root->right, sum, ans);

    if (root->left == NULL && root->right == NULL)
    {
        ans += sum;
    }
}
