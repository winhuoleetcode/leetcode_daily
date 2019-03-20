#include <iostream>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
bool isPalindrome(int x)
{
    if(x<0)
    {
        return false;
    }
    else
    {
        string a=to_string(x);
        for(int i=0,j=a.size()-1;i<a.size();j--,i++)
        {
            if(a[i]!=a[j])
            {

               return false;
            }
        }
    }
    return true;
}
int main()
{
    cout<<isPalindrome(1)<<endl;
    return 0;
}
