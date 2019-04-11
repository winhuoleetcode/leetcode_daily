//这个题想通过动态规划写出来，可代码实现比较复杂，所以参考一下别人的回溯法。
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		helper("",res,n,0,0);
		return res;
	}
	/*回溯法解决该问题
	回溯算法实际上一个类似枚举的搜索尝试过程，主要是在搜索尝试过程中寻找问题的解，当发现已不满足求解条件时，就“回溯”返回，尝试别的路径。回溯法是一种选优搜索法，按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为“回溯点”。许多复杂的，规模较大的问题都可以使用回溯法，有“通用解题方法”的美称。”
	*/
	void helper(string cur, vector<string> &res, int n, int left, int right)
	{
		//因为right是右括号，数量=n 表明此时已经找到一个结果
		if (right == n)
		{
			res.push_back(cur);
		}
		//可以添加一个左括号
		if (left < n)
		{
			helper(cur+'(',res,n,left+1,right);
		}
		//添加一个右括号
		if (right < left)
		{
			helper(cur+')',res,n,left,right+1);
		}
	}
	 
};
