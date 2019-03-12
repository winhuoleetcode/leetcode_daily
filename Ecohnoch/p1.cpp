#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict_tmp;
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); ++i){
            int key = target - nums[i];
            auto iter = dict_tmp.find(nums[i]);
            if(iter != dict_tmp.end()){
                ans[0]= iter->second;
                ans[1] = i;
                return ans;
            }else{
                dict_tmp[key] = i;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> test = {2, 7, 8, 10};
    vector<int> ans = s.twoSum(test, 9);
    cout<<(ans[0])<<" "<<ans[1];
    return 0;
}
