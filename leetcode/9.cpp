#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        if (x < 0)
        {
            return false;
        }
        for (int i = 0; i < (int)s.length() / 2; ++i)
        {
            if (s[i] != s[(int)s.length() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    int n;
    for (;;)
    {
        cin >> n;
        Solution s;
        bool isp = s.isPalindrome(n);
        if (isp)
        {
            cout << "Is Palindrome!" << endl;
            continue;
        }
        cout << "Isn't Palindrome!" << endl;
    }
    return 0;
}