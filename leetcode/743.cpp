#include <iostream>
using namespace std;

// 我的答案
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        if (!(n & (n - 1)))
        {
            return true;
        }
        return false;
    }
};

// LeetCode卷王的答案
class _Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & -n) == n ? true : false;
    }
};

int main()
{
    int n;
    Solution s;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        if (s.isPowerOfTwo(n))
        {
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
    return 0;
}