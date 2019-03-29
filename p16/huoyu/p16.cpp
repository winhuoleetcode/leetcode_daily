#include<iostream>
#include <vector>
#include<algorithm>
#include<set>
#include<unordered_map>
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int ans=nums[0]+nums[1]+nums[2];
    for(int i=0;i<nums.size()-2;++i)
    {
        int m=i+1;
        int n=nums.size()-1;
        while(m<n)
        {
            int x=nums[i]+nums[m]+nums[n];
            if(abs(x-target)<abs(ans-target))
            {
                ans=x;
            }
            if(x>target)
            {
                n--;
            }
            else if(x<target)
            {
                m++;
            }
            else
            {
                return target;
            }
        }
    }
    return ans;
}