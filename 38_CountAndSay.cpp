#include <iostream>
#include <string>
using namespace std;
//记录repeat次数，并根据次数和当前字符，追加字符到新字符串中
class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1";
        for(int i=2;i<=n;i++)
        {
            s = _countAndSay(s);
        }
        return s;
    }
private:
    string _countAndSay(string s)
    {
        int count = 0;
        string s_format;
        for(int i=0;i<s.size();i++)
        {
            count++;
            if(i==s.size()-1 || s[i]!=s[i+1])
            {
                s_format.push_back(count+'0');
                s_format.push_back(s[i]);
                count = 0;
            }
        }
        return s_format;
    }
};
int main()
{
    Solution slu;
    cout<<slu.countAndSay(4);
    return 0;
}