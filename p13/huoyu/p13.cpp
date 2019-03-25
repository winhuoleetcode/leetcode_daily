#include <iostream>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int romanToInt(string s)
{
    vector<char> m={'M','D','C','L','X','V','I'};
    vector<int> n={1000,500,100,50,10,5,1};
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<m.size();++j)
        {
            if(s[i]==m[j])
            {
                 ans+=n[j];
            }
        }


    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='C'&&s[i+1]=='M')
        {
            ans-=200;
        }
        if(s[i]=='C'&&s[i+1]=='D')
        {
            ans-=200;
        }
        if(s[i]=='X'&&s[i+1]=='C')
        {
            ans-=20;
        }
        if(s[i]=='X'&&s[i+1]=='L')
        {
            ans-=20;
        }
        if(s[i]=='I'&&s[i+1]=='X')
        {
            ans-=2;
        }
        if(s[i]=='I'&&s[i+1]=='V')
        {
            ans-=2;
        }
    }
    return ans;
    //"CM","CD""XC""XL""IX","IV",900,400,90,40,9,4
}

int main()
{
    cout<<romanToInt("IV");
}
