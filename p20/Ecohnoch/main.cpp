#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> a;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                a.push(0);
            }else if(s[i] == ')'){
                if(a.empty() || a.top() != 0) return false;
                a.pop();
            }else if(s[i] == '['){
                a.push(1);
            }else if(s[i] == ']'){
                if(a.empty() || a.top() != 1) return false;
                a.pop();
            }else if(s[i] == '{'){
                a.push(2);
            }else if(s[i] == '}'){
                if(a.empty() || a.top() != 2) return false;
                a.pop();
            }
        }
        return true;
    }
};


int main(){
    Solution s;
    string test = "()[]{}}";
    cout<<s.isValid(test)<<endl;


    return 0;
}
