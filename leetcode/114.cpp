#include <iostream>
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

class Solution
{
    TreeNode *pt(TreeNode *p)
    {
        // 退出条件：遇到空指针则返回空指针
        if (!p)
        {
            return nullptr;
        }

        // 创建变量存储子树转化链表后的尾结点
        TreeNode *left_leaf;
        TreeNode *right_leaf;
        left_leaf = pt(p->left);
        right_leaf = pt(p->right);

        // 若该结点为叶子节点，返回该结点本身
        if (!left_leaf && !right_leaf)
        {
            return p;
        }

        // 若存在左子树
        if (left_leaf)
        {
            // 将左子树转化链表后的尾结点指向右子树
            left_leaf->right = p->right;

            // 将右指针指向左子树转化的链表
            p->right = p->left;
            p->left = nullptr;
        }

        // 若没有右子树，返回值改为左子树转化的链表尾结点
        if (!right_leaf)
        {
            right_leaf = left_leaf;
        }

        return right_leaf;
    }

public:
    void flatten(TreeNode *root)
    {
        pt(root);
    }
};

class _Solution
{

private:
    TreeNode *pre;

    int DFS(TreeNode *p)
    {
        // 退出条件：如果指针为空，直接返回
        if (!p)
        {
            return 0;
        }

        // 修改前一个结点的数据
        pre->left = nullptr;
        pre->right = p;

        // 更新pre指针
        pre = p;

        // 创建变量存储左子树和右子树
        TreeNode *left = p->left;
        TreeNode *right = p->right;

        // 遍历左子树和右子树
        DFS(left);
        DFS(right);

        return 0;
    }

public:
    _Solution()
    {
        pre = nullptr;
    }

    void flatten(TreeNode *root)
    {
        TreeNode temp;
        pre = &temp;
        DFS(root);
    }
};

TreeNode *create(int n)
{
    TreeNode *p = new TreeNode(n);
    return p;
}

int main()
{
    TreeNode *root = create(1);
    TreeNode *p = root;
    p->left = create(2);
    p = p->left;
    p->left = create(3);
    p->right = create(4);
    p = root;
    p->right = create(5);
    p = p->right;
    p->right = create(6);
    _Solution s;
    p = root;
    s.flatten(root);
    while (p)
    {
        if (p->left)
        {
            cout << "error" << endl;
            system("pause");
        }
        cout << p->val << ' ';
        p = p->right;
    }
    return 0;
}