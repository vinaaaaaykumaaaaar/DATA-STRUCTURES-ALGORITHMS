#include <bits/stdc++.h>
using namespace std;

// ========================================================
// 1. COMMON LEETCODE DATA STRUCTURES
// ========================================================
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ========================================================
// 2. EASY PRINTING (vectors, 2D, pairs, lists)
// ========================================================
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i + 1 < v.size())
            os << ", ";
    }
    os << "]";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &vv)
{
    os << "[\n";
    for (const auto &row : vv)
    {
        os << "  " << row << "\n";
    }
    os << "]";
    return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// Linked List helpers
ListNode *createList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode *head)
{
    cout << "[";
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << "]\n";
}

// TreeNode print (in-order) - add more if you need
void printTreeInorder(TreeNode *root)
{
    if (!root)
        return;
    printTreeInorder(root->left);
    cout << root->val << " ";
    printTreeInorder(root->right);
}

// ========================================================
// 3. SUPER POWERFUL DEBUG MACRO (your best friend)
// ========================================================
// Usage inside any function: debug(i, nums[i], currentSum);
// Output: [i, nums[i], currentSum] = 0 7 9
void _debug_print() { cerr << endl; }

template <typename T>
void _debug_print(T t) { cerr << t; }

template <typename T, typename... Args>
void _debug_print(T t, Args... args)
{
    cerr << t << " ";
    _debug_print(args...);
}

#define debug(...)                             \
    do                                         \
    {                                          \
        cerr << "[" << #__VA_ARGS__ << "] = "; \
        _debug_print(__VA_ARGS__);             \
        cerr << endl;                          \
    } while (0)

// ========================================================
// 4. YOUR SOLUTION CLASS (paste LeetCode signature here)
// ========================================================
class Solution
{
public:
    int findMax(vector<int> &nums)
    {
        int maxVal = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
            }
            debug(i, nums[i], maxVal); // spy line - watch what happens each step
        }

        return maxVal;
    }
};
// ========================================================
// 5. TEST HARNESS - WRITE ALL YOUR TEST CASES HERE
// ========================================================
int main()
{
    Solution sol;

    vector<int> nums = {3, 7, 2, 9, 1};
    int result = sol.findMax(nums);
    cout << "Answer: " << result << " (Expected: 9)\n";

    cout << "--------------------------" << endl;

    vector<int> nums1 = {3, 7, 2, 9};
    cout << nums1 << "\n";

    cout << "\nAll tests finished! Check above output.\n";
    cout << "Wrong answer? Look at the debug() lines above for every step!\n";

    return 0;
}