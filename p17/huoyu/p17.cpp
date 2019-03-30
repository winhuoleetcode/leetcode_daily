class Solution {
public:
    vector<string> letterCombinations(string digits) {
            vector<string> num={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    for(int i=0;i<digits.size();i++)
    {
        if(ans.size()!=0)
        {
            int k=num[digits[i]-'0'].size();
            vector<string> temp;
            for(int x=0,y=0;x<ans.size()*k;++x)
            {
                temp.push_back(ans[y]);
                if((x+1)%k==0)
                    y++;
            }
            for(int x=0,y=0;x<temp.size();++x,++y)
            {
                y=y%k;
                temp[x]+=num[digits[i]-'0'][y];
            }
            ans=temp;
        }
        else
        {
            string a="";
            for( int j=0;j<num[digits[i]-'0'].size();++j)
            {
                a=+num[digits[i]-'0'][j];
                ans.push_back(a);
                a="";
            }
        }
    }
    return ans;
    }
};