#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

string num2str(int n){
    if(n < 10){
        return string(1, (char)(n + '0'));
    }
    string ans;
    while(n){
        ans += (n%10);
        n /= 10;
    }

    string realAns;
    for(int i = ans.size() - 1; i >= 0; --i){
        realAns += ans[i];
    }
    return realAns;

}

class Solution {
public:
    string countAndSay(int n) {
        int i = 0;
        string a1 = "1";
        string a2 = "11";
        string a3 = "21";
        if(n == 1) return a1;
        if(n == 2) return a2;
        if(n == 3) return a3;
        string cur = a3, tmp = "";
        i = 3;
        while(i < n){
            int start = 0;
            char cur_ch = cur[0];
            for(int i = 0; i < cur.size(); ++i){
                if(cur[i] == cur_ch){

                }else{
                    tmp = tmp + num2str(i - start);
                    tmp = tmp + cur_ch;
                    cur_ch = cur[i];
                    start = i;
                }
            }
            tmp = tmp + num2str(cur.size() - start);
            tmp = tmp + cur_ch;

            cur = tmp;
            tmp = "";


            i ++;
        }
        return cur;
    }
};


//int main(){

//    int a = INT_MAX;
//    cout<<a + 2<<endl;


//    return 0;

//}


int main(){
    Solution s;
    cout<<s.countAndSay(7);
}
