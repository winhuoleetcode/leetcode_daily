#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution_On2 {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        if(height.size() == 1) return height[0];
        int W = 0;
        for(int i = 0; i < height.size() - 1; ++i){
            for(int j = i + 1; j < height.size(); ++j){
                W = max(W, (j - i)*min(height[i], height[j]));
            }
        }
        return W;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        if(height.size() == 1) return height[0];
        int W = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            W = max(W, (j - i) * min(height[i], height[j]));
            if(height[i] < height[j]){
                i ++;
            }else{
                j --;
            }
        }

        return W;
    }
};



int main(){
    vector<int> p = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout<<s.maxArea(p)<<endl;
    return 0;
}
