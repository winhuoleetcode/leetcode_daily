#include <iostream>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
string intToRoman(int num) {
    vector<string> s={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int> n={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string ans;
    for(int i=0;i<13;++i)
    {
        while(num>=n[i])
        {
            num-=n[i];
            ans+=s[i];
        }
    }
    return ans;
}
int main()
{
    cout<<intToRoman(22);
}
