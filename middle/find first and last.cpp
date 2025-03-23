/*
@34:给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。



写这个题目之前我写了33，但是我又没想到正确的解题思路，应该还是缺少练习

核心思路：既然只要开始位置和结束位置，我们只需要分开来用两次二分查找就行了


以下是代码
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=0;
        int last=0;
        int left=0;
        int n=nums.size();
        int right=n-1;

        if(n==0)
        return {-1,-1};
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if (nums[mid]==target)
            {
                first=mid;
                right=mid-1;
            }else if(nums[mid]>target){
                right=mid-1;
            }
            else left=mid+1;
        }
        if (nums[first]!=target)
        return {-1,-1};
        left=0;
        right=n-1;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                last=mid;
                left=mid+1;
            }else if(nums[mid]>target)
            right=mid-1;
            else if (nums[mid]<target)
            left=mid+1;
        }
        return {first,last};
    }
};