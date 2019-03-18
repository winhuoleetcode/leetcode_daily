#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long int ans = 0;
        deque<int> s;
        bool m = false;
        if(x < 0){
            if(x == INT_MIN) return 0;
            x = -x;
            m = true;
        }
        while(x){
            s.push_back(x % 10);
            x /= 10;
        }

        while(s.front() == 0) s.pop_front();
        if(s.size() >= 11) return 0;
        while(!s.empty()){
            long int w = pow(10, s.size() - 1);
            long int tmp = s.front() * w;
            ans += tmp;
            s.pop_front();
        }

        if(ans > INT_MAX) return 0;
        if(m) return -ans;
        return ans;
    }
};



int main(){
    int test = -2050011001, test2 = 3;
    Solution s;
    cout<<s.reverse(test)<<endl;
    return 0;
}
