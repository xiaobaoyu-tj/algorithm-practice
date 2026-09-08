#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] > i) {
                    if (dp[i] == 0) {
                        dp[i] = -1;//说明不能进行兑换
                    }
                    break;
                }
                else {
                    if (!dp[i]) {
                        if (dp[i - coins[j]] != -1) {
                            dp[i] = 1 + dp[i - coins[j]];
                        }
                    }
                    else {
                        if (dp[i - coins[j]] != -1) {
                            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                        }
                    }
                }
            }
            if (!dp[i])dp[i] = -1;
        }
        return dp[amount];
    }
};