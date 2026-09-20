#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = -1;
        vector<int> dp(n, -1);

        int i = 0, j = 0;
        int windowSum = arr[0];

        while (i < n && j < n) {
            if (windowSum == target) {
                dp[i] = j;
                windowSum -= arr[i];
                ++i;

                if (j < i && i < n) {
                    windowSum += arr[i];
                    ++j;
                }
            } else if (windowSum < target) {
                ++j;
                if (j < n) {
                    windowSum += arr[j];
                }
            } else {
                windowSum -= arr[i];
                ++i;

                if (j < i && i < n) {
                    windowSum += arr[i];
                    ++j;
                }
            }
        }

        vector<int> minlen(n + 1, n + 1);
        for (int i = n - 1; i >= 0; --i) {
            minlen[i] = minlen[i + 1];
            if (dp[i] != -1) {
                int currentLength = dp[i] - i + 1;
                minlen[i] = min(minlen[i], currentLength);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (dp[i] == -1) {
                continue;
            }

            int j = dp[i];
            int leftLength = j - i + 1;
            int rightLength = minlen[j + 1];

            if (rightLength <= n) {
                int totalLength = leftLength + rightLength;
                if (ans == -1 || totalLength < ans) {
                    ans = totalLength;
                }
            }
        }

        return ans;
    }
};
