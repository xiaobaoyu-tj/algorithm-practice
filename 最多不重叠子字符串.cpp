#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        map<char, int> first, last;
        map<char, int> seenFromLeft, seenFromRight;

        for (int i = 0; i < n; ++i) {
            if (seenFromLeft[s[i]] == 0) {
                first[s[i]] = i;
                seenFromLeft[s[i]]++;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (seenFromRight[s[i]] == 0) {
                last[s[i]] = i;
                seenFromRight[s[i]]++;
            }
        }

        vector<int> least(n + 1, -1);

        for (int i = 0; i < n; ++i) {
            if (first[s[i]] != i) {
                continue;
            }

            int right = last[s[i]];
            map<char, int> used;
            least[i] = right;

            for (int j = i; j <= right; ++j) {
                if (used[s[j]] == 0) {
                    if (first[s[j]] != i && first[s[j]] != j) {
                        least[i] = -1;
                        break;
                    }
                    used[s[j]]++;
                    right = max(right, last[s[j]]);
                    least[i] = right;
                }
            }
        }

        vector<int> dp1(n + 1, 0);
        vector<int> dp2(n + 1, 0);
        vector<int> nextStart(n + 1, -1);

        for (int i = n - 1; i >= 0; --i) {
            if (least[i] == -1) {
                dp2[i] = dp2[i + 1];
                nextStart[i] = nextStart[i + 1];
                continue;
            }

            int right = least[i];
            dp1[i] = 1 + dp2[right + 1];

            if (dp1[i] > dp2[i + 1]) {
                dp2[i] = dp1[i];
                nextStart[i] = i;
            } else {
                dp2[i] = dp2[i + 1];
                nextStart[i] = nextStart[i + 1];
            }
        }

        vector<string> ans;
        int index = 0;

        while (index < n) {
            int start = nextStart[index];
            if (start == -1) {
                break;
            }

            ans.push_back(s.substr(start, least[start] - start + 1));
            index = least[start] + 1;
        }

        return ans;
    }
};
