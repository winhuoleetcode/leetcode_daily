#include <iostream>
#include<vector>
using namespace std;


double findMedianSortedArrays(vector<int> nums1, vector<int> nums2)
{
    int sumNum=nums1.size()+nums2.size();
    double ans=0;
    int sum=0;
    int aleady=0;
    if(sumNum%2==0)
    {
        int n=sumNum/2;
        int i=0;
        int j=0;
        while(aleady<n+1)
        {
            if(nums1.size()==0)
            {
                ans=double(double(nums2[n]+nums2[n-1])/2);
                return ans;
            }
            if(nums2.size()==0)
            {
                ans=double(double(nums1[n]+nums1[n-1])/2);
                return ans;
            }
            if(nums1[i]<=nums2[j])
            {

                if(aleady==n||aleady==n-1)
                {
                    sum+=nums1[i];
                }
                i++;
                aleady++;
                if(i==nums1.size())
                {
                    i--;
                    nums1[i]=INT_MAX;
                }
            }
            else
            {

                if(aleady==n||aleady==n-1)
                {
                    sum+=nums2[j];
                }
                 j++;
                 aleady++;
                 if(j==nums2.size())
                 {
                     j--;
                     nums2[j]=INT_MAX;
                 }
            }

        }
        ans=(double)sum/(2.0);
    }
    else

    {
        int n=sumNum/2+1;
        int i=0;
        int j=0;
        while(aleady<n)
        {
            if(nums1.size()==0)
            {
                ans=double(nums2[n-1]);
                return ans;
            }
            if(nums2.size()==0)
            {
                ans=double(nums1[n-1]);
               return ans;
            }
            if(nums1[i]<=nums2[j])
            {

                if(aleady==n-1)
                {
                    sum=nums1[i];
                }
                i++;
                aleady++;
                if(i==nums1.size())
                {
                    i--;
                    nums1[i]=INT_MAX;
                }
            }
            else
            {

                if(aleady==n-1)
                {
                    sum=nums2[j];
                }
                j++;
                aleady++;
                if(j==nums2.size())
                {
                    j--;
                    nums2[j]=INT_MAX;
                }
            }
            ans=(double)sum;
        }

    }
    return ans;
}
int main()
{
    vector<int> a;
    vector<int> b;
    //a.push_back(1);
    //a.push_back(2);
    b.push_back(1);
   b.push_back(4);
    cout<<findMedianSortedArrays(a,b)<<endl;
}
