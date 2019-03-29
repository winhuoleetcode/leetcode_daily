#include<iostream>
#include <vector>
#include<algorithm>
#include<set>
#include<unordered_map>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
        {
            return vector<vector<int>>();
        }
        sort(nums.begin(),nums.end());
        if(nums[0]>0|| nums[nums.size() - 1] < 0)
        {
            return vector<vector<int>>();
        }
        if(nums[0]==0&&nums[nums.size()-1]==0)
        {
            return vector<vector<int>>({{0,0,0}});
        }
        set<vector<int>> ans;
        unordered_map<int,int> hash1;
        for(int i = 0; i < nums.size(); ++i)
        {
            hash1[nums[i]] = i;
        }
        for(int i=0;i<nums.size()-1;++i)   
        {
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
//超时
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size() < 3)
        {
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-2;i++)
        {
            if(nums[i] == nums [i+1]) continue;
            int target = -nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l < r)
            {
                int sum = nums[l] + nums[r];
                if(sum > target) r--;
                else if(sum < target) l++;
                else 
                {
                    vector<int>tripset = {nums[i],nums[l],nums[r]};
                    ans.push_back(tripset);
                    while(nums[l+1] == nums[l]) l++;
                    while(nums[r-1] == nums[r]) r--;
                }
            }
            
        }
        return ans;
    }
};