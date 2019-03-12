class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tar;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                if(nums[i]+nums[j]==target)
                {
                    tar.push_back(i);
                    tar.push_back(j);
                    return tar;
                }
            }
        }
        return tar;
    }
};