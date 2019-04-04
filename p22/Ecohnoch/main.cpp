#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool stop(unordered_map<string, int> table){
    for(auto item = table.begin(); item != table.end(); ++item){
        if(item->second != 0) return true;
    }
    return false;
}

bool check(string s){
    int pos = 0, neg = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '(') pos ++;
        else neg ++;
        if(pos < neg) return false;
    }
    return true;
}

int find01(string s, int in){
    int p = 0;
    for(int i = 0; i < s.size() - 1; ++i){
        if(s[i] == '(' && s[i + 1] == ')'){
            if(p == in)
                return i;
            p++;
        }
    }
    return -1;
}

string change01(string s, int pos){
    string ans = "";
    for(int i = 0; i < s.size(); ++i){
        if(i == pos){
            ans += ")";
            continue;
        }
        if(i == pos + 1){
            ans += "(";
            continue;
        }
        ans += s[i];
    }
    return ans;
}

int findAll01(string s){
    int ans = 0;
    for(int i = 0; i < s.size() - 1; ++i){
        if(s[i] == '(' && s[i + 1] == ')'){
            ans += 1;
        }
    }
    return ans;
}

void doo(unordered_map<string, int> &hashMap){
    for(auto item = hashMap.begin(); item != hashMap.end(); ++item){
        if(item->second != 0){
            int lenn = item->second;
            for(int i = 0; i < lenn; ++i){
                int pos = find01(item->first, i);
                string newString = change01(item->first, pos);

                if(!check(newString)) item->second -= 1;
                else{

                    if(hashMap.find(newString) != hashMap.end()) item->second -= 1;
                    else{
                        hashMap[newString] = findAll01(newString);
                        item->second -= 1;
                    }
                }
            }

        }
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans = {};

        unordered_map<string, int> hashMap;
        string tmp(n, '(');
        tmp += string(n, ')');
        hashMap[tmp] = 1;

        while(stop(hashMap)){
            doo(hashMap);
        }


        for(auto item = hashMap.begin(); item != hashMap.end(); ++item){
//            cout<<item->first<<" "<<item->second<<endl;
            ans.push_back(item->first);
        }




        return ans;
    }
};


int main(){
    Solution s;
    auto p = s.generateParenthesis(1);
    return 0;
}
