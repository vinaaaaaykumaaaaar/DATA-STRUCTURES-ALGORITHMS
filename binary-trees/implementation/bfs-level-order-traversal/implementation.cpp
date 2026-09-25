#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> level_order_traversal(TreeNode *root)
{
    vector<vector<int>> result;

    if (root == nullptr)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> levelValues;

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            levelValues.push_back(node->val);

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }

        result.push_back(levelValues);
    }
    return result;
}

int main()
{
}