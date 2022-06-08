#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // 自己写的
    ListNode *_addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool index = false;
        ListNode *sum = new ListNode(l1->val + l2->val);
        if (sum->val > 9)
        {
            sum->val -= 10;
            index = true;
        }
        l1 = l1->next;
        l2 = l2->next;
        ListNode *p = sum;
        while (l1 && l2)
        {
            ListNode *temp = new ListNode(l1->val + l2->val);
            if (index)
            {
                temp->val++;
                index = false;
            }
            if (temp->val > 9)
            {
                temp->val -= 10;
                index = true;
            }
            p->next = temp;
            p = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *last = nullptr;
        if (l1)
        {
            last = l1;
        }
        if (l2)
        {
            last = l2;
        }
        if (!last)
        {
            if (index)
            {
                p->next = new ListNode(1);
                p = p->next;
            }
            return sum;
        }
        p->next = last;
        p = last;
        while (index)
        {
            if (p->val == 9)
            {
                p->val = 0;
                if (!p->next)
                {
                    p->next = new ListNode(0);
                }
                p = p->next;
                continue;
            }
            p->val++;
            p = p->next;
            break;
        }
        return sum;
    }
    // 参照了大佬写的以后写的
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool index = false;
        ListNode *sum = new ListNode(0);
        ListNode *p = sum;
        for (;;)
        {
            if (l1)
            {
                p->val += l1->val;
            }
            if (l2)
            {
                p->val += l2->val;
            }
            if (index)
            {
                p->val++;
                index = false;
            }
            if (p->val > 9)
            {
                p->val -= 10;
                index = true;
            }
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
            if (!l1 && !l2)
            {
                break;
            }
            p->next = new ListNode(0);
            p = p->next;
        }
        if (index)
        {
            p->next = new ListNode(1);
            p = p->next;
        }
        return sum;
    }
};

int main()
{
    int a1[10] = {0}, a2[10] = {0};
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < 10; i++)
    {
        a1[i] = (int)(s1[9 - i] - 0x30);
        a2[i] = (int)(s2[9 - i] - 0x30);
    }
    ListNode *l1, *l2;
    ListNode *p, *q;
    l1 = new ListNode(a1[0]);
    l2 = new ListNode(a2[0]);
    p = l1;
    q = l2;
    for (int i = 1; i < 10; i++)
    {
        p->next = new ListNode(a1[i]);
        q->next = new ListNode(a2[i]);
        p = p->next;
        q = q->next;
    }
    Solution s;
    ListNode *sum = s.addTwoNumbers(l1, l2);
    string str;
    while (sum)
    {
        str = (char)(sum->val + 0x30) + str;
        sum = sum->next;
    }
    cout << str << endl;
    return 0;
}