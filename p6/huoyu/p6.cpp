#include <iostream>
#include<vector>
#include<string>
#include<memory.h>
using namespace std;

string convert(string s, int numRows) {
         string ans;
         if(numRows==1)
         {
             for(int i=0;i<s.size();++i)
             {
                  ans+=s[i];
             }
              return ans;
          }
         if(numRows==2)
         {
             string ou;
             string ji;
             for(int i=0;i<s.size();++i)
             {
                 if(i%2==0)
                 {
                     ou+=s[i];
                 }
                 else
                 {
                     ji+=s[i];
                 }
             }
             return ou+ji;
         }

        int numLists=((s.size()/(2*numRows-2))+1)*(numRows-1);
        int sortNum=0;

        int j=0;//行
        int k=0;//列
        int first=1;
        vector<vector<char> > a(numRows);
        for(int i=0;i<numRows;i++)
        {a[i].resize(numLists);}


        //memset(a, '*', sizeof(a));
        cout<<a[0][0];
        for(int i=0;i<s.size();++i)
        {
            sortNum=(i)/(2*numRows-2);
            if(i%(2*numRows-2)<numRows)
            {
                a[j][sortNum*(numRows-1)]=s[i];
                j++;
                k=sortNum*(numRows-1);
            }
            else
            {
                if(first)
                {
                    j=numRows-2;
                    k++;
                    first=0;
                }


                a[j][k]=s[i];
                j--;k++;
            }
            if(i%(2*numRows-2)==2*numRows-3)
            {
                first=1;
            }

        }
        for(int i=0;i<numRows;++i)
        {
            for(int j=0;j<numLists;++j)
            {
                if(a[i][j]!='\0')
                {
                    ans+=a[i][j];
                }
            }
        }
        return ans;
    }



int main()
{
    string ddd="ABC";
    cout<<convert(ddd,2)<<endl;
    return 0;
}
