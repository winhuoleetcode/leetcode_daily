#include <iostream>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int myAtoi(string str)
{
    bool sign=true;
    bool begin_word=true;
    bool read_number=false;
    long long ans=0;
    long long min=(long long)INT_MAX+1;
    if(str.size()==0)
    {
        return 0;
    }
    for(int i=0;i<str.size();++i)
    {
          if(str[i]==' '&&begin_word){}
          else if(str[i]=='-'&&begin_word)
          {
              begin_word=false;
              read_number=true;
              sign=false;
          }
          else if(str[i]=='+'&&begin_word)
          {
              begin_word=false;
              read_number=true;
          }
          else if((str[i]>'9'||str[i]<'0')&&begin_word)
          {
              return 0;
          }
          else if(str[i]<='9'&&str[i]>='0')
          {
              read_number=true;
              begin_word=false;
              ans=(str[i]-48)+ans*10;
              if(ans>INT_MAX&&sign)
              {
                  return INT_MAX;
              }
              if(ans>min&&!sign)
              {
                  return INT_MIN;
              }

          }
          else if((str[i]>'9'||str[i]<'0')&&read_number)
          {
              break;
          }
    }
    if(!sign)
    {
        ans=-ans;
    }
    return int(ans);
}
int main()
{
    string aaa="+-2";
    cout<<myAtoi(aaa)<<endl;
    return 0;
}
