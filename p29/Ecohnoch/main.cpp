#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1)  return INT_MIN;
        if(divisor == 1)  return dividend;
        if(divisor == -1) return -dividend;
        if(dividend == 0) return 0;
        long int di = fabs(dividend), div = fabs(divisor), ans = 0;
        for(int i = 31; i >= 0; i--){
            if((di>>i) >= div){
                ans += (1<<i);
                di = di - (div<<i);
            }
        }
        if((dividend > 0 && divisor > 0 ) || dividend < 0 && divisor < 0){
            return ans;
        }else{
            return -ans;
        }
    }
};

int main(){
    Solution s;
    int di = 10, div = -3;
    cout<<s.divide(di, div);

    return 0;
}
