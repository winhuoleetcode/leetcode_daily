#include <iostream>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
string longestCommonPrefix(vector<string>& strs)
{
    if(strs.size()==0)
    {
        return "";
    }

    int min=strs[0].size();
    bool a=true;
    for(int i=0;i<strs.size() ;i++)
    {
        if(strs[i].size()<min)
        {
            min=strs[i].size();
        }
    }
    int ans_num=0;
    string ans="";
    for(int i=0;i<min;i++)
    {
        for(int j=0;j<strs.size()-1;++j)
        {
            if(strs[j][i]!=strs[j+1][i])
            {
                a=false;
                break;
            }
        }
        if(!a)
        {
            break;
        }
        ans_num++;
    }
    if(ans_num!=0)
    {
        for(int i=0;i<ans_num;i++)
        {
            ans+=strs[0][i];
        }
    }
    return ans;
}

int main()
{
    vector<string> strs={"flower"};
    cout<<longestCommonPrefix(strs);
}
