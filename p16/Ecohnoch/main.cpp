#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 3) return nums[0] + nums[1] + nums[2];
        unordered_map<int, vector<int>> hashMap;
        int lenn = nums.size();
        for(int i = 0; i < lenn - 1; ++i){
            for(int j =  i + 1; j < lenn; ++j){
                hashMap[target - nums[i] - nums[j]] = vector<int>({i, j});
            }
        }
        int minn = 0x3f3f3f3f, ans = 0;
        for(auto iter = hashMap.begin(); iter != hashMap.end(); ++iter){
            for(int k = 0; k < lenn; ++k){
                if(k != iter->second[0] && k != iter->second[1]){
                    if(minn > abs(iter->first - nums[k])){
                        ans = nums[iter->second[0]] + nums[iter->second[1]] + nums[k];
                        minn = abs(iter->first - nums[k]);
                    }
                }
            }
        }
        return ans;
    }
};




int main(){
    cout<<'p';
    vector<int> p = {-1, 2, 1, -4};
    Solution s;

    cout<<s.threeSumClosest(p, 1)<<endl;
    return 0;
}
