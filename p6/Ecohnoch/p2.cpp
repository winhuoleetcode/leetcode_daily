#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= numRows) return s;
        if(s.size() == 1) return s;
        if(numRows == 1)  return s;

        string ans = "";
        int x = floor((s.size() - 1) * 1.0 / (numRows - 1));
        cout<<x<<endl;
        bool slash = (x % 2 == 0) ? true : false;


        for(int i = 0; i <= x; i += 2){
            ans += s[i * (numRows - 1)];
        }
        if(slash){

            int inter = s.size() - 1 - x * (numRows - 1);
            cout<<" "<<inter<<endl;
            for(int i = 1; i <= numRows - 2; ++i){
                ans += s[i];
                if(i <= inter){
                    for(int j = 2; j <= x; j += 2){
                        ans += s[j * (numRows - 1) - i];
                        ans += s[j * (numRows - 1) + i];
                    }
                }else{
                    for(int j = 2; j <= x; j += 2){
                        if(j == x){
                            ans += s[j * (numRows - 1) - i];
                            break;
                        }
                        ans += s[j * (numRows - 1) - i];
                        ans += s[j * (numRows - 1) + i];
                    }
                }
            }
            for(int i = 0; i < x; i += 2){
                ans += s[(i + 1) * (numRows - 1)];
            }
        }else{
            int inter = numRows - (s.size() - 1 - (x) * (numRows - 1)) - 1;
            cout<<" "<<inter<<endl;
            for(int i = 1; i <= numRows - 2; ++i){
                ans += s[i];
                if(i < inter){
                    for(int j = 2; j < x; j += 2){
                        ans += s[j * (numRows - 1) - i];
                        ans += s[j * (numRows - 1) + i];
                    }
                }else{
                    for(int j = 2; j < x; j += 2){
                        ans += s[j * (numRows - 1) - i];
                        ans += s[j * (numRows - 1) + i];
                    }
                    ans += s[s.size() - 1 - (i - inter)];
                }
            }
            for(int i = 1; i <= x; i += 2){
                ans += s[(i) * (numRows - 1)];
            }
        }



        return ans;
    }
};



int main(){
    string test = "ABCD";
    cout<<test.size()<<endl;
    Solution s;
    cout<<s.convert(test, 3)<<endl;
    return 0;
}
