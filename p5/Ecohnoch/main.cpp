#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int f[1005][1005];


class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") return "";
        if(s.size() == 1){
            string ans = "";
            return ans + s[0];
        }
        if(s.size() == 2){
            string ans = "";
            if(s[0] == s[1]) return s;
            return ans + s[0];
        }

        memset(f, -1, sizeof(f));
        int nn = s.size(), ans = 0, ansPos = 0;
        for(int i = 0; i < nn; ++i){
            f[i][i] = 1;
            if(i >= 1 && s[i] == s[i - 1]){
                f[i - 1][i] = 1;
                if(ans < 2){
                    ansPos = i - 1;
                    ans = 2;
                }
            }
        }
        for(int i = 3; i <= nn; ++i){
            for(int j = 0; j < nn - i + 1; ++j){
                int endd = j + i - 1;
                if(s[j] == s[endd] && f[j + 1][endd - 1] == 1){
                    f[j][endd] = 1;
                    ansPos = j;
                    ans = i;
                }
            }
        }

        if(ans == 0 && ansPos == 0){
            string ans = "";
            return ans + s[0];
        }
        return s.substr(ansPos, ans);


    }
};

int main(){

    Solution s;
    string test = "ccc";
    string ans = s.longestPalindrome(test);
    cout<<ans;
    cout<<ans.size()<<endl;


    return 0;

}
