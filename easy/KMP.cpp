/*
  @ 28:给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
  如果 needle 不是 haystack 的一部分，则返回  -1 。


*/
//本题为初学KMP算法根据教程写出来的，后配上注释，以便以后复习
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
     void GetNext(vector<int>& next,string needle)//得到next数组
    {
        next[0]=-1;//初始化next[0]为-1，因为当字符串为1的时候一定没有公共前缀  我们令其为-1
        int i=0,k=-1;//i表示为当前位置也可以说是最长后缀的最后一个字母，k表示与当前位置相等的公共前缀所指向的最后一个位置
        while (i+1<needle.size())
        {
            if (k==-1||needle[i]==needle[k])//判断两字符是否相等或k的值是否为-1
            {
                next[i+1]=k+1;//新字符串的最长公共前缀的值即为k+1
                i++;
                k++;
            }
            else {
                k=next[k];//回退k
            }
        }
    }
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        if (m<n)
        return -1;
        vector<int> next(n);
        GetNext(next,needle);
        int i=0,j=0;
        while (j<m)
        {
            if(i==-1||haystack[j]==needle[i])
            {
                i++;
                j++;
                if (i==n)
                return j-n;
            }
            else {
                i=next[i];
            }
        }
        return -1;
    }
};