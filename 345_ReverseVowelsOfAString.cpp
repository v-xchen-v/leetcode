#include <iostream>
#include <string>
#include <set>
using namespace std;
//两个游标指向要交换的元素，分别向从字符头部和字符尾部向中间逼近;
//如果都是是元音则交换，对于元音的判断使用set数据结构，注意元音的大小写字符
class Solution {
public:
    set<char> vowels;
    Solution()
    {
        setUpVowels();
    }
    void setUpVowels()
    {
        vowels.insert({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
    }
    string reverseVowels(string s) {
        int len = s.size();
        int start=0,end=len-1;
        while(start<end)
        {
            bool leftIsVowel = vowels.count(s[start]);
            bool rightIsVowel = vowels.count(s[end]);
            if(leftIsVowel && rightIsVowel)
                swap(s[start], s[end]);
            start++;
            end--;
            if(leftIsVowel && !rightIsVowel)
                start--;
            if(!leftIsVowel && rightIsVowel)
                end++;
        }
        return s;
    }
};
int main()
{
    // string s = "leetcode";
    string s = "hello";
    // getline(cin, s); //这个getline函数在<string>头文件下
    Solution slu;
    cout<<slu.reverseVowels(s);
    return 0;
}