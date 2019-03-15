#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int f[256], ans = 0, start = 0;
        memset(f, 0, sizeof(f));

        for(int i = 0; i < s.size(); ++i){
            if(f[s[i]] == 0 || f[s[i]] < start){
                ans = max(ans, i - start + 1);
                f[s[i]] = i + 1;
            }else{
                start = f[s[i]];
                f[s[i]] = i + 1;
            }
        }
        return ans;
    }

};

int main(){

    Solution s;

    string test = "abcabcbb";
    int ans = s.lengthOfLongestSubstring(test);
    cout<<ans<<endl;
    return 0;

}
