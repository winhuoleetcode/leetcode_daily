class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> Str;
        int ans=0;
        int ans_=0;
        int n_start=0;
        for(int i=0;i<s.size();i++)
        {
            auto iter=find(Str.begin(),Str.end(),s[i]);
            if(iter==Str.end())
            {
                Str.push_back(s[i]);
                ans_++;
                if(ans_>ans)
                {
                    ans=ans_;
                }
            }
            else
            {
                
                if(ans_>ans)
                {
                    ans=ans_;
                }
                ans_=0;
                Str.clear();
                n_start++;
                i=n_start;
                Str.push_back(s[i]);
                ans_++;
                
            }
            
        }
        
        return ans;
        
    }
};