#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Solution
{
private:
    int cmp(string str1, string str2)
    {
        // 若长度不同，若str1更长则返回正数，反之负数
        if (str1.length() != str2.length())
        {
            return str1.length() - str2.length();
        }

        // 初始化
        int a[26];
        memset(a, 0, 4 * 26);
        int len = str1.length();

        // 遍历两个字符串
        for (int i = 0; i < len; ++i)
        {
            ++a[(int)(str1[i] - 'a')];
            --a[(int)(str2[i] - 'a')];
        }

        // 若两字符串加减结果不为0，返回该结果
        for (int i = 0; i < 26; ++i)
        {
            if (a[i])
            {
                return a[i];
            }
        }

        return 0;
    }

    int sort(vector<string> &strs, int left, int right)
    {
        if (left >= right)
        {
            return 0;
        }
        int logl = left;
        int logr = right;
        string mid = strs[left];
        ++left;
        bool usl = false;
        while (left <= right)
        {
            if (usl)
            {
                if (cmp(strs[left], mid) > 0)
                {
                    strs[right + 1] = strs[left];
                    usl = false;
                }
                ++left;
            }
            else
            {
                if (cmp(mid, strs[right]) > 0)
                {
                    strs[left - 1] = strs[right];
                    usl = true;
                }
                --right;
            }
        }
        int logm = 0;
        if (usl)
        {
            logm = right + 1;
        }
        else
        {
            logm = left - 1;
        }
        strs[logm] = mid;
        sort(strs, logl, logm - 1);
        sort(strs, logm + 1, logr);
        return 0;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        sort(strs, 0, (int)strs.size() - 1);

        vector<string> tmp;         // 待装入的列表
        vector<vector<string>> ret; // 待返回的列表
        tmp.push_back(strs[0]);
        for (int i = 1; i < (int)strs.size(); ++i)
        {
            if (cmp(strs[i - 1], strs[i]))
            {
                ret.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(strs[i]);
        }
        ret.push_back(tmp);
        return ret;
    }
};

int main()
{
    vector<vector<string>> list;
    vector<string> strs;
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    Solution s;
    list = s.groupAnagrams(strs);
    return 0;
}