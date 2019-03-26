#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return vector<vector<int>>();

        sort(nums.begin(), nums.end());


        if(nums[0] > 0 || nums[nums.size() - 1] < 0) return vector<vector<int>>();
        if(nums[0] == 0 && nums[nums.size() - 1] == 0) return vector<vector<int>>({{0, 0, 0}});

        set<vector<int>> ans;
        unordered_map<int, int> hash1;
        for(int i = 0; i < nums.size(); ++i){
            hash1[nums[i]] = i;
        }
        for(int i = 0; i < nums.size() - 1; ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                auto tmp =  hash1.find(-(nums[i] + nums[j]));
                if(tmp != hash1.end()){
                    int ind = tmp->second;
                    if(ind != i && ind != j){
                        vector<int> tmpVec = {nums[ind], nums[i], nums[j]};;
                        sort(tmpVec.begin(), tmpVec.end());
                        ans.insert(tmpVec);
                    }
                }
            }
        }
        vector<vector<int>> realAns(ans.begin(), ans.end());
        return realAns;
    }
};





int main(){
    cout<<'p';
    vector<int> p = {-1, 0, 1, 2, -1, -4};
    Solution s;

    vector<vector<int>> ss =  s.threeSum(p);
    for(auto item: ss){
        cout<<item[0]<<" "<<item[1]<<" "<<item[2]<<endl;
    }
    return 0;
}
