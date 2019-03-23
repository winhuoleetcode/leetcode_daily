#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;



int nums[7]  = {1000, 500, 100, 50, 10, 5, 1};
char hash1[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

int cmp(char a, char b){
    if(a == 'I' && (b == 'V' || b == 'X')) return 1;
    if(a == 'X' && (b == 'L' || b == 'C')) return 10;
    if(a == 'C' && (b == 'D' || b == 'M')) return 100;
    return 0;
}

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            if(i != 0){
                for(int j = 0; j < 7; ++j){
                    if(s[i] == hash1[j]){
                        ans += nums[j];
                        if(cmp(s[i - 1], s[i])){
                            ans -= 2 * cmp(s[i - 1], s[i]);
                        }
                        break;
                    }
                }
            }else{
                for(int j = 0; j < 7; ++j){
                    if(s[i] == hash1[j]){
                        ans += nums[j];
                        break;
                    }
                }
            }

        }
        return ans;
    }
};





int main(){
    string p = "MCMXCIV";
    Solution s;
    cout<<s.romanToInt(p)<<endl;
    return 0;
}
