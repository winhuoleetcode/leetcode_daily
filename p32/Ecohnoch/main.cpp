#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

int dp[10000][10000];
bool check(string s){
    bool flag = false;
    int leftnum = 0, rightnum = 0, lenn = s.size();
    for(int i = 0; i < lenn; ++i){
        if(s[i] == '('){
            leftnum += 1;
        }else{
            rightnum += 1;
        }
        if(rightnum > leftnum) return false;
    }
    if(leftnum != rightnum) return false;
    return true;
}

class Solution {
public:
    int longestValidParentheses(string s) {
        int lenn = s.size();
        if(lenn == 0) return 0;
        if(lenn == 1) return 0;
        if(lenn == 2 && s[0] == '(' && s[1] == ')') return 2;
        if(lenn == 2) return 0;

//        memset(dp, -1, sizeof(dp));
        int start = 0, res = 0;
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    start = i + 1;
                }else{
                    st.pop();
                    if(st.empty()){
                        res = max(res, i - start + 1);
                    }else{
                        res = max(res, i - st.top());
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    string test ="(()()(())((";
    cout<<s.longestValidParentheses(test)<<endl;
    return 0;
}
