/*
和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。

给你一个整数数组 nums ，请你在所有可能的 子序列 中找到最长的和谐子序列的长度。

数组的 子序列 是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。

@此题的代表意义：哈希表用于统计+条件筛选的典型问题

@核心：哈希表统计频率，检查相邻键的频率和
*/
//核心思路：题目中说明最大值和最小值差一，则可利用哈希表来解决，要注意c++17的结构化绑定的使用，还有判断边界条件只要遍历当前key+1的迭代器不等于最后的迭代器就行
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> seen;
        for (int num :nums)
        {
            seen[num]++;
        }
        int res=0;
        for (auto &[key,val] :seen)
        {
            if(seen.find(key+1)!=seen.end())
            res=max(res,val+seen[key+1]);
        }
        return res;
    }
}; 