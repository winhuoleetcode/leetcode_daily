#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0) return;
        if(nums.size() == 1) return;
        int leftpos = -1, rightpos = -1, lenn = nums.size();
        for(int i = lenn - 2; i >= 0; --i){
            if(nums[i + 1] > nums[i]){
                leftpos = i;
                break;
            }
        }

        if(leftpos == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        for(int i = lenn - 1; i > leftpos; --i){
            if(nums[i] > nums[leftpos]){
                rightpos = i;
                break;
            }
        }
        int tmp = nums[leftpos];
        nums[leftpos] = nums[rightpos];
        nums[rightpos] = tmp;
        sort(nums.begin() + leftpos + 1, nums.end());

//        cout<< rightpos<<endl;

        return;

    }
};

int main(){
    Solution s;
    vector<int> test = {1, 2, 4, 6, 5, 3};
    s.nextPermutation(test);

    for(auto item: test){
        cout<<item<<" ";
    }
    return 0;
}
