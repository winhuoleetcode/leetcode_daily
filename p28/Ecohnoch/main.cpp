#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenn1 = haystack.size(), lenn2 = needle.size();
        for(int i = 0; i < lenn1 - lenn2; ++i){
            string tmp = haystack.substr(i, lenn2);
            if(tmp == needle){
                return i;
            }
        }
        return -1;


    }
};

int main(){
    Solution s;
    string test = "hello";
    string needle = "ll";

    return 0;
}
