#include <ctime>
#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
private:
    unsigned short int lp;
    unsigned short int *a;
    unsigned short int max;

public:
    Solution()
    {
        lp = 0;
        a = new unsigned short int[128];
        memset(a, 65535, 2 * 128);
        max = 0;
    }

    ~Solution()
    {
        delete[] a;
    }

    int lengthOfLongestSubstring(string s)
    {
        unsigned short int len = (unsigned short int)s.size();
        for (unsigned short int i = 0; i < len; i++)
        {
            if (a[(unsigned short int)s[i]] != 65535 && a[(unsigned short int)s[i]] >= lp)
            {
                if (i - lp > max)
                {
                    max = i - lp;
                }
                lp = a[(unsigned short int)s[i]] + 1;
            }
            a[(unsigned short int)s[i]] = i;
        }
        if (len - lp > max)
        {
            max = len - lp;
        }
        return (int)max;
    }
};

int _main()
{
    Solution s;
    string str;
    cin >> str;
    if (str == "exit")
    {
        return 1;
    }
    if (str == "auto")
    {
        int n;
        cout << "Input number of character in the string: " << endl;
        cin >> n;
        str = "";
        srand((unsigned int)time(nullptr));
        for (int i = 0; i < n; i++)
        {
            str += (char)(rand() % 94 + 0x21);
        }
        // cout << "string: " << str << endl;
    }
    cout << "Down" << endl;
    int n = s.lengthOfLongestSubstring(str);
    cout << "lenth: " << n << endl;
    return 0;
}

int main()
{
    for (;;)
    {
        if (_main())
        {
            break;
        }
    }
    return 0;
}