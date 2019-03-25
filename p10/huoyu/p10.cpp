class Solution {
public:
    bool isMatch(string s, string p) {
 // match[i][j]==true 表示s的前i位和p的前j位是匹配的
        vector< vector<bool> > match(s.length() + 3, vector<bool>(p.length() + 3, false));
        
        // 边界条件为i=0 j=0 j=1
        // j=0时p为空串，只能匹配空串，其他默认为false
        match[0][0] = true;
        // j=1时p只有一个字符，只能匹配一个字符，其他全部为false
        match[1][1] = s[0] == p[0] || p[0] == '.';
        // i=0时s为空串，p只有类似a*b*c*d*这样的形式才可以成功匹配
        for (int j = 2; j < p.length() + 1; j += 2)
            // 前0位和前j-2位是匹配的，且第j位是*
            match[0][j] = match[0][j - 2] && p[j - 1] == '*';


        // i表示s的前i位，j表示p的前j为
        for (int i = 1; i < s.length() + 1; i++)
            for (int j = 2; j < p.length() + 1; j++)
            {
                if (p[j - 1] != '*')
                    // 前i-1位和前j-1位是匹配的，且第i位和第j位是匹配的
                    match[i][j] = match[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                else
                    //当p[j-1]出现0次时，前i位和前j-2位是匹配的
                    //当p[j-1]出现1次或多次时，第i位一定匹配第j-1位，且前i-1位一定和前j位是匹配的。
                    match[i][j] = match[i][j - 2] || match[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
            }
        return match[s.length()][p.length()];
    }
};