/*
@1337  给你一个大小为 m * n 的矩阵 mat，矩阵由若干军人和平民组成，分别用 1 和 0 表示。

请你返回矩阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。

如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。

军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。

        本题思路不难 即对每一行的一计数存入某一个数组 比较每行1的个数，且要求结果是索引数组（这就直接导致我写不出来），之前并没有写过这种写法
        如：        vector<pair<int,int>> array      array.push_back({ans,i});    sort(array.begin(), array.end());
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res(k);
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> array;
        for (int i=0;i<m;++i)
        {
            int ans=0;
            for (int j=0;j<n;j++)
            {
                if (mat[i][j])
                ans++;
                else break;
            }
            array.push_back({ans,i});
        }
        sort(array.begin(), array.end());
        for(int i = 0; i < k; ++i)
            res[i] = array[i].second;
        return res;
    }
};