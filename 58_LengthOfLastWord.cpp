#include <iostream>
using namespace std;
//处理了末尾空格的问题后，就简化为简单的计数问题了
class Solution{
public:
    int lengthOfLastWord(string s)
    {
        int tail = s.size()-1;
        int len = 0;
        while(tail>=0 && s[tail]==' ') tail--;
        while(tail>=0 && s[tail]!=' ')
        {
            tail--;
            len++;
        }
        return len;
    }
};

//一个复杂了的方法
// class Solution{
// public:
//     int lengthOfLastWord(string s)
//     {
//         int idx1=-1,idx2=-1;
//         for(int i=s.size()-1;i>=0;i--)
//         {
//             if(s[i]!=' ')
//             {
//                 idx2 = i;
//                 break;
//             }
//         }
//         if(idx2==-1) return 0;
//         for(int i=idx2-1;i>=0;i--)
//         {
//             if(s[i]==' ')
//             {
//                 idx1 = i;
//                 break;
//             }
//         }
//         return idx2-idx1;
//     }
// };

int main()
{
    string s = "Hello World ";
    Solution slu;
    cout<<slu.lengthOfLastWord(s)<<endl;
    return 0;
}