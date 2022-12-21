#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        int king = 0;
        bool a[14];
        memset(a, false, 14);
        for (int i = 0; i < 5; ++i)
        {
            if (nums[i] == 0)
            {
                ++king;
                continue;
            }
            if(a[nums[i]]==true)
            {
                return false;
            }
            a[nums[i]] = true;
        }
        bool s = false;
        int cnt = 0;
        for (int i = 1; i < 14; ++i)
        {
            if (!s && a[i] == true)
            {
                s = true;
            }

            if (cnt == 5)
            {
                return true;
            }

            if (s)
            {
                ++cnt;
                if (a[i] == false)
                {
                    --king;
                }
            }

            if (king < 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> list;
    for (int i = 0; i < 5; ++i)
    {
        int temp = 0;
        cin >> temp;
        list.push_back(temp);
    }
    cout << s.isStraight(list) << endl;
    return 0;
}