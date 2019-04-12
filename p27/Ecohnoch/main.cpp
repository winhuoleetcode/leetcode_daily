#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int start = 0, lenn = nums.size();
        while(start + 1 <= lenn){
            if(nums[start] == val){
                nums.erase(nums.begin() + start);
                lenn = nums.size();
            }else{
                start ++;
            }
        }
        return nums.size();

    }
};

int main(){
    Solution s;
    vector<int> a = {1, 0, 0, 2};
    int ans = s.removeElement(a, 2);
    cout<<ans<<endl;

    return 0;
}
