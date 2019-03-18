#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

int a[20];
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x / 10 == 0) return true;
        if(x / 100 == 0 && x % 10 == x % 100) return true;
        int p = x, bit = 0;
        while(p){
            a[bit] = p % 10;
            p /= 10;
            bit ++;
        }
        int start = 0, end = bit - 1;
        while(start < end){
            if(a[start] != a[end]) return false;
            start ++;
            end --;
        }
        return true;
    }
};



int main(){
    int test = 301003;
    Solution s;
    cout<<s.isPalindrome(test)<<endl;
    return 0;
}
