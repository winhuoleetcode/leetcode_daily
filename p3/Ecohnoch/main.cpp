#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int *f = new int[s.size()];
        memset(f, 0, sizeof(f));
        f[0] = 1;

        for(int i = 1; i < s.size(); ++i){

            bool flag = true;
            for(int j = 0; j <= f[i - 1]; ++j){
                if(s[i] == s[i - j - 1]){
                    flag = false;
                    f[i] = j + 1;

                    break;
                }
            }
            if(flag){
                f[i] = f[i - 1] + 1;
            }
        }

        int ans = -1;
        for(int i = 0; i < s.size(); ++i){
            if (ans < f[i]){
                ans = f[i];
            }
        }
        return ans;
    }

};

int main(){

    Solution s;

    string test = "alouzxilkaxkufsu";
    int ans = s.lengthOfLongestSubstring(test);
    cout<<ans<<endl;
    return 0;

}
