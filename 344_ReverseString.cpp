#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        int start=0,end=len-1;
        while(start<end)
        {
            swap(s[start], s[end]);
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