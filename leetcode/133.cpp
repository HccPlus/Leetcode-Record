#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    bool *a; // hash表记录该索引是否被遍历过

    Node *clone(Node *node, Node *last)
    {
        // 若已被遍历过则直接return
        if (a[node->val])
        {
            return nullptr;
        }

        // clone一个节点并更新标记
        Node *p = new Node(node->val);
        last->neighbors.push_back(p);
        p->neighbors.push_back(last);
        a[node->val] = true;
        last = p;

        // 循环遍历邻居节点
        for (int i = 0; i < (int)node->neighbors.size(); ++i)
        {
            clone(node->neighbors[i], last);
        }

        return p;
    }

public:
    Solution()
    {
        a = new bool[105];
        memset(a, false, 105);
    }

    Node *cloneGraph(Node *node)
    {
        return clone(node, nullptr);
    }

};

Node *set(int val)
{
    Node *p = new Node(val);
    return p;
}

int com(Node *p1, Node *p2)
{
    p1->neighbors.push_back(p2);
    p2->neighbors.push_back(p1);
    return 0;
}

int main()
{
    Node *p1 = set(1);
    Node *p2 = set(2);
    Node *p3 = set(3);
    Node *p4 = set(4);
    Node *p5 = set(5);
    com(p1, p2);
    com(p2, p3);
    com(p3, p5);
    com(p1, p4);

    Solution s;
    Node *temp = nullptr;
    cout << temp << endl;
    temp = s.cloneGraph(p1);
    return 0;
}