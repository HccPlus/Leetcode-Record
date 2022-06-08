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
private:
    int min;
    bool inited;

    int DFS(TreeNode *p, int layers)
    {

        // 退出条件1：遇到空结点直接退出
        if (!p)
        {
            return 0;
        }

        // 退出条件2：层数大于等于min则退出
        if (inited && layers >= min)
        {
            return 0;
        }

        // 退出条件3：遇到叶子结点刷新最小层数后退出
        if (!p->left && !p->right)
        {
            if (inited)
            {
                if (layers < min)
                {
                    min = layers;
                }
            }
            else
            {
                min = layers;
                inited = true;
            }
            return 0;
        }

        // 遍历下一层
        layers++;
        DFS(p->left, layers);
        DFS(p->right, layers);
        return 0;
    }

public:
    Solution()
    {
        min = 0;
        inited = false;
    }

    int minDepth(TreeNode *root)
    {
        DFS(root, 1);
        return min;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *p = nullptr;
    p = root;
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p = p->right;
    p->left = new TreeNode(15);
    p->right = new TreeNode(7);
    p = root;
    Solution s;
    cout << s.minDepth(p) << endl;
    return 0;
}