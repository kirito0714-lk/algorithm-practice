/*
@ 349：给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

 时间复杂度：O（n）

 leetcode349.核心思路：定义两个哈希表并且使用语法nums.begin(),nums.end()来进行去重操作然后取交集即可

@ 350：给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，
应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
 leetcode350.核心思路：依题所说，我们需要不去重的交集，我们可以先用哈希表seen来存储nums1和nums2中较小数组中每个数的出现次数，然后遍历nums2如果能在
 seen中找到且出现次数不为1，我们就可以将这个数插入一个新建立的vector容器中，同时使该数出现次数减一

*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std; 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2;
        for (int num :nums2)
        {
            if(set1.count(num))
            set2.insert(num);
        }
        return vector<int>(set2.begin(),set2.end());
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash;
        vector<int> res;
        if(nums1.size()>nums2.size())
        return intersection(nums2,nums1);
        for (int num:nums1)
        hash[num]++;
        for (int i:nums2)
        {
            if(hash.count(i)&&hash[i])
            res.push_back(i);
        }
        return res;
    }
};