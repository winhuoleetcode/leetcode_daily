#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() <= 3) return vector<vector<int>>({});
        if(nums.size() == 4){
            if(nums[0] + nums[1] + nums[2] + nums[3] == target) return vector<vector<int>>({nums});
            return vector<vector<int>>({});
        }

        set<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int lenn = nums.size();

        for(int i = 0; i < lenn - 3; ++i){
            for(int j = i + 1; j < lenn - 2; ++j){
                for(int k = j + 1; k < lenn - 1; ++k){
                    for(int w = k + 1; w < lenn; ++w){
                        if(nums[i] + nums[j] + nums[k] + nums[w] == target){
                            vector<int> tmp = {nums[i], nums[j], nums[k], nums[w]};
                            sort(tmp.begin(), tmp.end());
                            ans.insert(tmp);
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());

    }
};


int main(){
    Solution s;
    vector<int> p = {1, 0, -1, 0, -2, 2};
    cout<<s.fourSum(p, 0).size()<<endl;
    return 0;
}
