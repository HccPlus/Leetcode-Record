#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        ListNode *p = head;
        ListNode *q = head;
        int cnt = 0;
        q = q->next;
        while (p != q)
        {
            ++cnt;
            if (!q)
            {
                return nullptr;
            }
            p = p->next;
            q = q->next;
            if (!q)
            {
                return nullptr;
            }
            q = q->next;
        }
        q = q->next;
        p = head;
        while (p != q)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

int main()
{
    ListNode n0(0);
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n1;
    Solution s;
    cout << &n0 << endl;
    cout << &n1 << endl;
    cout << &n2 << endl;
    cout << &n3 << endl;
    cout << s.detectCycle(&n0) << endl;
}