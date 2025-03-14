//编写一个算法来判断一个数 n 是不是快乐数。

//「快乐数」 定义为：

//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果这个过程 结果为 1，那么这个数就是快乐数。
//如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
//核心思路：如果一个数不是快乐数，那么按照此流程算下来它一定会陷入循环，因为一个三位数它的最大的下一位数为243，因此它必定陷入循环，所以考虑使用unordered_set来记录数的唯一地址，每得到一个数就记录到里面去，如果有则说明不是快乐数，返回false
//快慢指针可以用来检测此类循环题
#include <iostream>
#include <unordered_set>
using namespace std;
//哈希表法
class Solution {
public:
int GetNext(int n)
{
    int sum=0;
    while (n>0)
    {
        int a=n%10;
        sum+=a*a;
        n/=10;
    }
    return sum;
}
    bool isHappy(int n)
    {
        unordered_set<int> seen;
        
        while(n!=1)
        {
            int b=GetNext(n);
            if(seen.count(b))
            return false;
            seen.insert(b);
            n=b;
        }
        return true;
    }

};
//快慢指针
class Solution1{
    public:
    int GetNext(int n)
    {
    int sum=0;
    while (n>0)
    {
        int a=n%10;
        sum+=a*a;
        n/=10;
    }
    return sum;
    }
    bool isHappy(int n)
    {
        int fast=n;int slow=n;
        do
        {
            slow=GetNext(slow);
            fast=GetNext(fast);
            fast=GetNext(fast);
        }while(slow!=fast);
        return slow==1;
    }
};
