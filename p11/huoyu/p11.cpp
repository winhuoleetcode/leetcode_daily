class Solution {
public:
    int maxArea(vector<int>& height) {
    int ans=0;
    int w=0;
    int l=0;
    for(int i=0;i<height.size()-1;++i)
    {
        for(int j=i+1;j<height.size();++j)
        {
            w=j-i;
            l=min(height[i],height[j]);
            if(w*l>ans)
            {
                ans=w*l;
            }
        }
    }
    return ans;
    }
};
//s2：面积取决于指针的距离和最小的值，所以如果移动大值 另一个也可能更小。
{
		 int max = 0;
		 for(int i = 0, j = a.length - 1; i < j ; ){
			 int minHeight = a[i] < a[j] ? a[i ++] : a[j --];
			 max = Math.max(max, (j - i + 1) * minHeight);
		 }
		 return max;
	 }