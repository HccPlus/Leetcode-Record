#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int *p, *q;
    int n1, n2;
    int i1, i2;

    int min(int *p, int *q)
    {
        if (!p)
        {
            return *q;
        }
        if (!q)
        {
            return *p;
        }
        if (*p > *q)
        {
            return *q;
        }
        return *p;
    }

    int adp()
    {
        p++;
        i1++;
        if (i1 >= n1)
        {
            p = nullptr;
        }
        return 0;
    }

    int adq()
    {
        q++;
        i2++;
        if (i2 >= n2)
        {
            q = nullptr;
        }
        return 0;
    }

    int add()
    {
        if (p && q)
        {
            if (*p > *q)
            {
                adq();
                return 0;
            }
            adp();
            return 0;
        }
        if (p)
        {
            adp();
            return 0;
        }
        if (q)
        {
            adq();
            return 0;
        }
        return 1;
    }

public:
    Solution()
    {
        p = nullptr;
        q = nullptr;
        n1 = 0;
        n2 = 0;
        i1 = 0;
        i2 = 0;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 初始化变量
        if (!nums1.empty())
        {
            p = &nums1[0];
            n1 = (int)nums1.size();
        }
        if (!nums2.empty())
        {
            q = &nums2[0];
            n2 = (int)nums2.size();
        }
        int sum = (int)nums1.size() + (int)nums2.size();

        // 若只有一个元素
        if (sum == 1)
        {
            if (nums1.empty())
            {
                return nums2[0];
            }
            return nums1[0];
        }

        // 若总元素数为奇数
        if (sum % 2 == 1)
        {
            for (int i = 0; i < sum / 2; i++)
            {
                add();
            }
            return min(p, q);
        }

        // 总元素数为偶数
        for (int i = 1; i < sum / 2; i++)
        {
            add();
        }
        int tmp1 = min(p, q);
        add();
        int tmp2 = min(p, q);
        return (double)(tmp1 + tmp2) / 2;
    }
};

int main()
{
    vector<int> v1;
    vector<int> v2;
    int n1, n2;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++)
    {
        int t = 0;
        cin >> t;
        v1.push_back(t);
    }
    for (int i = 0; i < n2; i++)
    {
        int t = 0;
        cin >> t;
        v2.push_back(t);
    }
    Solution s;
    double tmp = 0;
    tmp = s.findMedianSortedArrays(v1, v2);
    cout << tmp << endl;
}