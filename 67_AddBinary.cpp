#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    Solution():c('0'){}
    string addBiary(string a, string b)
    {
        string res;
        int len = max(a.size(), b.size());
        for(int i=1;i<=len;i++)
        {
            bool have_c = false;
            char aPlusb = addOneBinary(_getEleFromTail(a, i), _getEleFromTail(b, i), have_c);
            char aPlusbPlusc = addOneBinary(aPlusb, c, have_c);
            if(have_c) c = '1';
            else c = '0';
            res.push_back(aPlusbPlusc);
        }
        if(c) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
    char addOneBinary(char a, char b, bool &have_c)
    {
        if(a=='1'&&b=='1'){
            have_c = true;
            return '0';
        }
        return '0'+(a-'0')+(b-'0');
    }
    char _getEleFromTail(const string&s, int idx) //获取倒数第i个元素
    {   
        if(idx>s.size()) return '0';
        return s[s.size()-idx];
    }
private:
    char c;//进位
};
int main()
{
    string a = "1010";
    string b = "1011";
    Solution slu;
    cout<<slu.addBiary(a, b);
    return 0;
}