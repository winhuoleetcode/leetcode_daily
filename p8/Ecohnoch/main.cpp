#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

bool isNum(char ch){
    if(ch <= '9' && ch >='0') return true;
    return false;
}

class Solution {
public:
    int myAtoi(string str) {
        if(str == "") return 0;

        deque<int> q;
        int start = 0;
        bool m = false;
        while((str[start] == ' ') && start < str.size()) start ++;
        if(start == str.size()) return 0;
        if(!isNum(str[start]) && str[start] != '-' && str[start] != '+') return 0;

        if(str[start] == '-') m = true;


        for(int i = start + (m ? 1 : 0) + ((str[start] == '+')? 1 : 0); i < str.size(); ++i){
            if(isNum(str[i])){
                q.push_back(str[i] - '0');
            }else{
                break;
            }
        }
        while(q.front() == 0) q.pop_front();
        if(q.size() == 0) return 0;
        if(q.size() >= 11 && m == false) return INT_MAX;
        if(q.size() >= 11 && m)          return INT_MIN;

        long int ans = 0;
        int times = 0;
        while(!q.empty()){
            ans += (q.back() * pow(10, times));
            times ++;
            q.pop_back();
        }
        if(ans >= INT_MAX && m == false) return INT_MAX;
        if(ans - 1 >= INT_MAX && m)      return INT_MIN;

        if(m) return -ans;
        else return ans;
    }
};



int main(){
    string test = "  +00042";
    Solution s;
    cout<<s.myAtoi(test)<<endl;
    return 0;
}
