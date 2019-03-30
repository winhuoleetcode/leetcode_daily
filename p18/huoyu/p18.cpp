#include<iostream>
#include <vector>
#include<algorithm>
#include<set>
#include<string>
#include<unordered_map>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    if(nums.size()<4)
    {
        vector<vector<int>> a;
        return a;
    }
    set<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-3;i++)
    {
        for(int j=i+1;j<nums.size()-2;j++)
        {
            int m=j+1;
            int n=nums.size()-1;
            while(m<n)
            {
            while(nums[i]+nums[j]+nums[n]+nums[m]<target)
            {
                if(m<n)
                m++;
                else
                break;
            }
            if(nums[i]+nums[j]+nums[n]+nums[m]==target&m!=n)
            {
                vector<int>a ={nums[i],nums[j],nums[n],nums[m]};
                sort(a.begin(),a.end());
                ans.insert(a);
                if(m<n)
                m++;
                else
                break;
            }
            while(nums[i]+nums[j]+nums[n]+nums[m]>target)
            {
                if(n>m)
                n--;
                else
                break;
            }
            if(nums[i]+nums[j]+nums[n]+nums[m]==target&&m!=n)
            {
                vector<int>a ={nums[i],nums[j],nums[n],nums[m]};
                sort(a.begin(),a.end());
                ans.insert(a);
                if(n>m)
                n--;
                else
                break;
            }
            }
        }
    }
    vector<vector<int>>b(ans.begin(),ans.end());
    return b;

}
int main()
{
    vector<int> a={0, 0, 0, 0};
    int b=1;
    vector<vector<int>>c=fourSum(a,b);
    for(auto a:c)
    {
        for(auto b:a)
        {
            cout<<b;
        }
        cout<<endl;
    }


    return 0;
}
