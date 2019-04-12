#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int start = 0, endd = 1;
        int lenn = nums.size();
        while(start + 1 < lenn){
//            cout<<start<<" "<<endd<<" "<<lenn<<endl;
            if(nums[start] == nums[endd]){
                nums.erase(nums.begin() + endd);
                lenn = nums.size();
            }else{
                start ++;
                endd = start + 1;
            }
        }
        return nums.size();
    }
};

int main(){
    Solution s;
    vector<int> a = {1, 0, 0, 2};
    int ans = s.removeDuplicates(a);
    cout<<ans<<endl;

    return 0;
}
