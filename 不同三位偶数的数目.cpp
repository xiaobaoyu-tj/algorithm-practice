#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
typedef long long ll;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        //AAA,ABA,BAA,BBA,CBA
        //AAA:满足mp[A]>=3,A!=0
        //ABA:满足A!=0,mp[A]>=2
        //BAA:B!=0,MP[A]>=2
        //BBA,B!=0,MP[B]>=2
        //CBA,C!=0
        map<int, int>mp;
        int num1 = 0;//不同distinct digits的个数
        int num2 = 0;//不为0的distinct digits个数
        int num3 = 0;//含有个数>=2，且不为0的distinct digits个数
        int ans = 0;
        for (int i = 0; i < digits.size(); i++) {
            mp[digits[i]]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            num1++;
            if (it->first != 0)num2++;
            if (it->second >= 2 && it->first != 0)num3++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->first % 2 == 0) {
                //AAA
                if (it->first != 0 && it->second >= 3)ans++;
                //ABA
                if (it->first != 0 && it->second >= 2) {
                    ans += (num1 - 1);
                }
                //BAA
                if (it->second >= 2) {
                    if (it->first == 0) {
                        ans += num2;
                    }
                    else ans += (num2 - 1);
                }
                //BBA
                if (it->first != 0 && it->second >= 2)ans += (num3 - 1);
                else ans += num3;
                //CBA
                if (it->first == 0) {
                    ans += (num2 - 1) * num2;
                }
                else {
                    ans += (num2 - 1) * (num1 - 2);
                }
            }
        }
        return ans;
    }
};
