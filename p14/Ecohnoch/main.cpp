#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


bool check(vector<string>& strs, int start){
    char tmp;
    for(int i = 0; i < strs.size(); ++i){
        if(start >= strs[i].size()) return false;
        if(i == 0) tmp = strs[0][start];
        else if(strs[i][start] != tmp) return false;
    }
    return true;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int start = 0;
        while(check(strs, start)){start ++;}
        if(start == 0) return "";
        return strs[0].substr(0, start);
    }
};






int main(){
    vector<string> p = {"floor", "flow", "flight"};
    Solution s;
    cout<<s.longestCommonPrefix(p)<<endl;
    return 0;
}
