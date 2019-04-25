#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lenn = nums.size();
        if(lenn == 0) return 0;
        if(lenn == 1 && nums[0] >= target) return 0;
        if(lenn == 1) return 1;
        int start = 0, endd = lenn - 1;
        int mid = (start + endd) / 2;
        while(nums[mid] != target){
            mid = (start + endd) / 2;

            if(start == mid){
                if(nums[endd] == target) return endd;
                if(nums[start]== target) return start;
                if(nums[endd] < target) return lenn;
                if(nums[start] > target) return 0;
                return endd;
            }
            if(nums[mid] > target){
                endd = mid;
                int tmp = (start + endd) / 2;
                if(nums[tmp] < target){
                    while(nums[tmp] < target && nums[mid] > target){
                        tmp ++;
                        mid --;
                    }
                    if(nums[tmp] == target) return tmp;
                    if(nums[mid] == target) return mid;
                    if(nums[tmp] > target && nums[mid] < target) return tmp;
                }
            }else if(nums[mid] < target){
                start = mid;
                int tmp = (start + endd) / 2;
                if(nums[tmp] > target){
                    while(nums[tmp] > target && nums[mid] < target){
                        tmp --;
                        mid ++;
                    }
                    if(nums[tmp] == target) return tmp;
                    if(nums[mid] == target) return mid;
                    if(nums[tmp] < target && nums[mid] > target) return mid;
                }
            }else{
                return mid;
            }
        }
        if(nums[mid] == target) return mid;
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> test = {1, 3};
    cout<<s.searchInsert(test, 1)<<endl;
    return 0;
}
