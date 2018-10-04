#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//1. 简化问题，假如没有IV的形式，遍历累加即可得解

//2. 加上IV这种格式，观察Roman字符串，可以发现一个特点，
    //如果没有IV这种格式，从左到右千百个，一定是越来越小得。
    //而如果有IV这种格式，就是左数小于右数，对于这样得数，直接减去左边小的数即可
//方案就是在原来的基础上，判断相邻的两数大小关系，cur<right则result-=map[cur]，否则累加
class Solution
{
public:
    int result = 0;
    unordered_map<char, int> map;
    Solution()
    {
        setUp(map);
    }
    void setUp(unordered_map<char, int>& map)
    {
        map.insert({'I',1});
        map.insert({'V',5});
        map.insert({'X',10});
        map.insert({'L',50});
        map.insert({'C',100});
        map.insert({'D',500});
        map.insert({'M',1000});
    }
    void _roman2Int(const string &input, int idx)
    {
        if(idx>=input.size())
        {
            return;
        }

        char roman_cur = input[idx];
        char roman_right = idx+1<=input.size()-1?input[idx+1]:'#';
        if(idx+1<=input.size()-1 && map[roman_cur]<map[roman_right])
            result -= map[roman_cur];
        else    
            result += map[roman_cur];

        _roman2Int(input, idx+1);
    }
    int romanToInt(string input)
    {
        _roman2Int(input, 0);
        return result;
    }
};
int main()
{
    string input = "MCMXCIV";
    Solution slu;
    cout<<slu.romanToInt(input);
    return 0;
}