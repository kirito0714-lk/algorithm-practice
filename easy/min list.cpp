/*
@Leetcode 599:假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设答案总是存在。

 核心思路：本题首先使用unordered_map创建哈希表，存储list1中的字符串和其索引，然后遍历list2，用条件判断哈希表str中是否含list2中的字符串，同时判断
 其索引和是否比自己定义的min小，若小则进入语句块，再次判断二者是否相等，如果相等则不执行清空语句（非常重要，第一次的时候不知道），然后更新min值，且
 将list2[j]存入vector变量中，最后返回！！

*/
//半小时
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> str;
        vector<string> strch;
        int min=100000;
        int a[30]={0};
        for(int i=0;i<list1.size();i++)
        {
            str[list1[i]]=i;
        }
        for(int j=0;j<list2.size();j++)
        {
           if (str.count(list2[j])>0&&min>=j+str[list2[j]])
           {
            if(min!=j+str[list2[j]])
            strch.clear();
            min=j+str[list2[j]];
           
           strch.push_back(list2[j]);
           }
        }
       
        
        return strch;
    }
};