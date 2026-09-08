#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[n - 1] = 1;
        //dp是指的，必须要选择当前元素的最长递增子序列的长度
        for (int i = n - 2; i >= 0; i--) {
            int add = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    add = max(add, dp[j]);
                }
            }
            dp[i] = add + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
