#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int hashs[256];
        int hasht[256];
        memset(hashs, 0, 4 * 256);
        memset(hasht, 0, 4 * 256);
        for (int i = 0; i < (int)s.size(); i++)
        {
            hashs[(int)s[i]]++;
            hasht[(int)t[i]]++;
        }
        int sum = 0;
        for (int i = 0; i < 256; i++)
        {
            int temp = hashs[i] - hasht[i];
            if (temp > 0)
            {
                sum += temp;
            }
        }
        return sum;
    }
};

int main()
{
    Solution obj;
    string s, t;
    cin >> s >> t;
    cout << obj.minSteps(s, t) << endl;
    return 0;
}