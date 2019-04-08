#include<iostream>
#include <vector>
#include<stack>
#include<algorithm>
#include<set>
#include<string>
#include<unordered_map>
using namespace std;
bool isValid(string s)
{
    stack<char> sn;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
            sn.push(s[i]);
        }
        else
        {
            if(sn.empty())
            {
                return false;
            }
            if(s[i]==')'&&sn.top()=='(')
            {
                sn.pop();
            }
            else if(s[i]==']'&&sn.top()=='[')
            {
                sn.pop();
            }
            else if(s[i]=='}'&&sn.top()=='{')
            {
                sn.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(sn.empty())
    {
        return true;
    }
    return false;

}
int main()
{
    string a="]";
    cout<<isValid(a)<<endl;
    return 0;
}
