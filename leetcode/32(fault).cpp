#include <iostream>
using namespace std;

class Solution
{
private:
    int len;
    int con;

    int get_max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        return b;
    }

    int front(string s)
    {
        int max = 0;             // 最长有效子串
        int height = 0;          // 当前栈高
        int length = 0;          // 当前有效字串长度
        int len = (int)s.size(); // 字符串长度

        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '(')
            {
                ++height;
            }
            else
            {
                if (height == 0)
                {
                    length = 0;
                    continue;
                }
                --height;
                if (height == 0)
                {
                    max = get_max(max, length + 1);
                }
            }
            ++length;
        }
        con = max;
        return 0;
    }

    int back(string s)
    {
        int max = 0;             // 最长有效子串
        int height = 0;          // 当前栈高
        int length = 0;          // 当前有效字串长度
        int len = (int)s.size(); // 字符串长度

        for (int i = len - 1; i >= 0; --i)
        {
            if (s[i] == ')')
            {
                ++height;
            }
            else
            {
                if (height == 0)
                {
                    length = 0;
                    continue;
                }
                --height;
                if (height == 0)
                {
                    max = get_max(max, length + 1);
                }
            }
            ++length;
        }
        con = max;
        return 0;
    }

public:
    int longestValidParentheses(string s)
    {
        len = (int)s.size();
        int frt = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '(')
            {
                ++frt;
            }
            else
            {
                --frt;
            }
        }
        if (frt <= 0)
        {
            front(s);
        }
        else
        {
            back(s);
        }
        return con;
    }
};

int mai()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.longestValidParentheses(str) << endl;
    return 0;
}

int main()
{
    for (;;)
    {
        mai();
    }
    return 0;
}