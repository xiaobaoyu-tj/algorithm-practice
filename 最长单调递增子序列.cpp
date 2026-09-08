#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> getLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};
    vector<int> tails;      // 存储最小末尾值
    vector<int> tails_idx;  // 存储最小末尾值对应的原数组索引
    vector<int> prev(n, -1); // prev[i]前一个元素索引
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        // 二分查找第一个 >= x 的位置
        auto it = lower_bound(tails.begin(), tails.end(), x);
        int pos = it - tails.begin();
        if (it == tails.end()) {
            // 追加到末尾
            tails.push_back(x);
            tails_idx.push_back(i);
        }
        else {
            // 替换
            *it = x;
            tails_idx[pos] = i;
        }
        // 记录前驱
        if (pos > 0) {
            prev[i] = tails_idx[pos - 1];
        }
    }
    // 从最后一个 tails_idx 开始回溯重建序列
    vector<int> result;
    int idx = tails_idx.back();
    while (idx != -1) {
        result.push_back(nums[idx]);
        idx = prev[idx];
    }
    reverse(result.begin(), result.end());
    return result;
}