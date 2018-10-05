#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
//括号是从中间开始向两侧对称对应的，符合栈的顺序，因此就使用栈来匹配字符
class Solution
{
public:
    stack<char> p_st;
    unordered_map<char, char> matches{{'(',')'},{'{','}'},{'[',']'}};
    bool isValid(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(p_st.empty() || matches[p_st.top()]!=s[i])
                p_st.push(s[i]);
            else
                p_st.pop();
        }

        if(p_st.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    string s = "{[]}";
    Solution slu;
    cout<<slu.isValid(s)<<endl;
    return 0;
}