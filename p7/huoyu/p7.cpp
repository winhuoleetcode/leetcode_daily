 int reverse(int x) {
    long y=(long)x;
    bool sign=true;
    if(y<0)
    {
        sign=false;
        y=-y;
    }
    long ans=y%10;
    y=y/10;
    while(y!=0)
    {
        ans=ans*10+y%10;
        y=y/10;
    }
    if(!sign)
    {
        ans=-ans;
    }
        if(ans>INT_MAX||ans<INT_MIN)
        {
            ans=0;
        }
    return (int)ans;

    }