/*
@33.整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。


此为二分查找的第一个中等题，简单题固定套路，所以先刷中等题，综合来看，思路新颖，不容易想到，但是我相信总有这么一天我可以拿下


攀登的过程也许漫长，但山顶的风景一定值得


核心思路：由于该数组部分有序，且数字不会重复出现，所以就先算出中间值与nums[0]比较，判断前面部分是否有序，若有序，我们就看target是否在此范围内，不在就调整范围
按此方法不断缩小范围即可

以下为代码
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        if(n==0)
        return -1;

        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            return mid;
            if(nums[0]<=nums[mid])//注意此处的条件=可取，因为虽然nums数组里数字不重复，但是mid计算可能等于0，n为2的情况如果没有等号就无法进入判断就有bug。
            {
                if(nums[0]<=target&&target<nums[mid])
                right=mid-1;
                else 
                left=mid+1;
            }
            else{
                if(nums[mid]<target&&target<=nums[n-1])
                left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};