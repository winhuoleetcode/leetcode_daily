#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lenn = nums.size();
        if(lenn == 0) return vector<int>{-1, -1};
        if(lenn == 1 && nums[0] == target) return vector<int>{0, 0};
        if(lenn == 1) return vector<int>{-1, -1};
        if(lenn == 2 && nums[0] == target && nums[1] == target) return vector<int>{0, 1};
        if(lenn == 2 && nums[0] == target && nums[1] != target) return vector<int>{0, 0};
        if(lenn == 2 && nums[0] != target && nums[1] == target) return vector<int>{1, 1};
        if(lenn == 2) return vector<int>{-1, -1};


        int start = 0, endd = lenn - 1, mid = (start + endd) / 2;
        while(start < endd){
            mid = (start + endd) / 2;
            if(mid == start){
                if(nums[endd] == target) mid = endd;
                break;
            }
            if(nums[mid] < target){
                start = mid;
                continue;
            }else if(nums[mid] > target){
                endd = mid;
                continue;
            }else{
                break;
            }
        }
        if(nums[mid] == target){
            int first = mid, sec = mid;
            while(nums[first] == target && nums[sec] == target){
                first --;
                sec ++;
                if(first < 0 || sec > lenn - 1){
                    break;
                }
            }
            while(first >= 0 && nums[first] == target){
                first --;
            }
            while(sec <= lenn - 1 && nums[sec] == target){
                sec ++;
            }
            if(first + 1 == sec - 1){
                return vector<int>{mid, mid};
            }else{
                return vector<int>{first + 1, sec - 1};
            }


        }else{
            return vector<int>{-1, -1};
        }

    return vector<int>{-1, -1};
    }
};

int main(){
    Solution s;
    vector<int> test = {1, 2, 3};
    for(auto item: s.searchRange(test, 3)){
        cout<<item<<endl;
    }
    return 0;
}
