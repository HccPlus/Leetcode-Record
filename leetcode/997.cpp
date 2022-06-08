#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Solution
{
private:
    int *head;

    int note(vector<int> t)
    {
        head[t[0]] = -1;
        if (head[t[1]] != -1)
        {
            head[t[1]]++;
        }
        return 0;
    }

public:
    Solution()
    {
        head = nullptr;
    }

    int findJudge(int n, vector<vector<int>> &trust)
    {
        head = new int[n + 1];
        memset(head, 0, sizeof(int) * (n + 1));
        for (int i = 0; i < (int)trust.size(); i++)
        {
            note(trust[i]);
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (head[i] == n - 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> list;
    int n = 0;
    int num = 0;
    cin >> n;
    cin >> num;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        int a, b;
        cin >> a >> b;
        tmp.push_back(a);
        tmp.push_back(b);
        list.push_back(tmp);
    }
    Solution s;
    cout << s.findJudge(num, list) << endl;
    return 0;
}