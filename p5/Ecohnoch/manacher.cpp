#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int p[2005];

string init(string s){
    string ans(s.size() * 2 + 2, '#');
    ans[0] = '$';
    ans[1] = '#';
    for(int i = 2; i < s.size() * 2 + 2; ++i){
        if(i % 2 == 0)
            ans[i] = s[(int)i/2 - 1];
        else
            ans[i] = '#';
    }
    return ans;
}

void manacher(string s){
    int id = 0, mx = 0;
    for(int i = 1; i < s.size(); ++i){
        if(i < mx){
            p[i] = min(mx - i, p[2 * id - i]);
        }else{
            p[i] = 1;
        }
        for(; s[i + p[i]] == s[i - p[i]];)
            p[i] ++;
        if(mx < i + p[i]){
            mx = i + p[i];
            id = i;
        }
    }
}


class Solution {
public:
    string longestPalindrome(string s) {
        string ss = init(s);
        manacher(ss);
        int maxx = 0, pos = 0;
        for(int i = 0; i < ss.size(); ++i){
            if(maxx < p[i]){
                maxx = p[i];
                pos = i;
            }
        }
        maxx = maxx - 1;
        cout<<maxx<<" "<<pos<<endl;
        if(pos % 2 == 0)
            pos = (int)(pos / 2) - (int)(maxx / 2) - 1;
        else
            pos = (int)(pos / 2) - (int)(maxx / 2);
        return s.substr(pos, maxx);
    }
};

int main(){

    Solution s;
    string test = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    string ans = s.longestPalindrome(test);
    cout<<ans<<endl;


    return 0;

}
