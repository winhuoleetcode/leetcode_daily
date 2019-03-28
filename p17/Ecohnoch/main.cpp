#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<char>> hashtab = {
    {' '},
    {' '},
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
};



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return vector<string>({});
        vector<string> ans;
        int first = digits[0] - '0';

        for(int i = 0; i < hashtab[first].size(); ++i){
            string tmp = string(1, hashtab[first][i]);
            ans.push_back(tmp);
        }
        for(int i = 1; i < digits.size(); ++i){
            int indice = digits[i] - '0';
            int lenn = ans.size();
            int expandTimes = hashtab[indice].size();
            for(int j = 0; j < expandTimes - 1; ++j){
                for(int k = 0; k < lenn; ++k){
                    ans.push_back(ans[k]);
                }
            }
            for(int j = 0; j < expandTimes; ++j){
                for(int k = 0; k < lenn; ++k){
                    ans[k + lenn * j] += string(1, hashtab[indice][j]);
                }
            }
        }
        return ans;

    }
};




int main(){

    Solution s;
    vector<string> p = s.letterCombinations("23");
    for(string item:p){
        cout<<item<<endl;
    }
    cout<<p.size()<<endl;
    return 0;
}
