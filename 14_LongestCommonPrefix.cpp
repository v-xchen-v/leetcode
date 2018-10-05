#include <iostream>
#include <vector>
#include <string>
using namespace std;
//遍历vector<string>寻找common即可，注意string的size()方法返回值是unsigned int类型的，使用时尽量主要不能有负值，否则一定要转为int
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size()==0) return "";
        string s_res = "";
        int idx = 0;
        while(true)
        {   
            char c_col;
            for(int i=0;i<strs.size();i++)
            { 
                if(idx>(int)strs[i].size()-1) //为strs[i].size()转int非常重要，因为size()返回的是unsigned int，size()=0时，-1并不是-1而是一个非常大的数
                    return s_res;         

                if(i==0) 
                    c_col = strs[0][idx];
                else if(c_col!=strs[i][idx])
                    return s_res;
            }
            s_res.push_back(strs[0][idx]);
            idx++;
        }
        return s_res;
    }
};
int main()
{
    // vector<string> strs{"flower","flow","flight"};
    vector<string> strs{""};
    Solution slu;
    cout<<slu.longestCommonPrefix(strs);
    return 0;
}