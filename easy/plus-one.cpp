/*
@leetcode 66:给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

时间复杂度O(n*n)

核心思路：本题主要在于思维的转换，从后往前遍历，找到第一个不等于9的数，让其加一，并让这个数之后的所有数置为0，
如果找不到即说明全为9，则让数组多加一位并把首位置为一。


*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for (int i=n-1;i>=0;i--)
        {
            if(digits[i]!=9)
            {
                digits[i]++;
                for(int j=i+1;j<n;j++)
                {
                    digits[j]=0;
                }
                return digits;
            }
        }
        digits[0]=1;
        for (int k=1;k<n;k++)
        digits[k]=0;
        digits.push_back(0);
        return digits;
    }
};