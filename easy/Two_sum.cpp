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