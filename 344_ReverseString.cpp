#include <iostream>
#include <string>
using namespace std;
//两个游标指向要交换的元素，分别向从字符头部和字符尾部向中间逼近
class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        int start=0,end=len-1;
        while(start<end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};
int main()
{
    string s;
    getline(cin, s); //这个getline函数在<string>头文件下
    

    return 0;
}