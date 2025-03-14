//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//难度：简单
//核心思路：用哈希表记录每一个数的下标索引，当表中有目标元素target-nums[i]时返回其下标索引和此时的i
//避免双重循环，时间复杂度从O(n*n)优化到O(n)
代码实现：
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
    public:vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int,int> num;
        for (int i=0;i<nums.size();i++)
        {
            int element=target-nums[i];
            if(num.count(nums[i]))
            return {num[element],i};
            num[nums[i]]=i;
        }
    }

};
