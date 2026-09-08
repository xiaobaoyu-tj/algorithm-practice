#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[n - 1] = nums[n - 1];
        int ans = max(-10000, dp[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = max(nums[i], nums[i] + dp[i + 1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};