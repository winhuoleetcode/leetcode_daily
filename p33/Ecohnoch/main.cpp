#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lenn = nums.size();
        int start = 0, endd = lenn - 1;
        int mid = (lenn / 2);
        if(lenn == 0) return -1;
        if(target == nums[start]) return start;
        if(target == nums[endd])  return endd;
        if(target == nums[mid])   return mid;

        if(target > nums[start]){
        // left
//            cout<<"left"<<endl;
            while(nums[mid] != target){
                if(nums[mid] < nums[start]){
                    endd = mid;
                    mid = (mid + start) / 2;
                    if(mid == 0 || mid == endd) return -1;
                    continue;
                }

                if(nums[mid] < target){
                    start = mid;
                    mid = (mid + endd) / 2;
                    if(nums[mid] == target) return mid;
                    if(start >= endd || mid == start){
                        return -1;
                    }
                    continue;
                }else if(nums[mid] > target){
                    endd = mid;
                    mid = (mid + start) / 2;
                    if(nums[mid] == target) return mid;
                    if(start >= endd || mid == endd){
                        return -1;
                    }
                    continue;
                }
            }
            return mid;
        }else{
        // right
            cout<<"right"<<endl;
            while(nums[mid] != target){
                if(nums[mid] > nums[endd]){
                    start = mid;
                    mid = (mid + endd) / 2;
                    if(mid == 0 || mid == start) return -1;
                    continue;
                }

                if(nums[mid] < target){
                    start = mid;
                    mid = (mid + endd) / 2;
                    if(nums[mid] == target ) return mid;
                    if(start >= endd || mid == start) {
                        return -1;
                    }
                    continue;
                }else if(nums[mid] > target){
                    endd = mid;
                    mid = (mid + start) / 2;
                    if(nums[mid] == target ) return mid;
                    if(start >= endd || mid == endd){
                        return -1;
                    }
                    continue;
                }
            }
            return mid;
        }

    }
};

int main(){
    Solution s;
    vector<int> test = {3,5,1};
    cout<<s.search(test, 0)<<endl;
    return 0;
}
