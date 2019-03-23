#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string quickAns[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

class Solution {
    public:
        string intToRoman(int num) {
            string ans = "";
            for(int i = 0; i < 13; ++i){
                int times = num / nums[i];
                for(int j = 0; j < times; ++j){
                    ans += quickAns[i];
                }
                num = num % nums[i];
            }
            return ans;
        }
};





int main(){
    int p = 3;
    Solution s;
    cout<<s.intToRoman(p)<<endl;
    return 0;
}
