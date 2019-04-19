#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

bool check(string s, unordered_map<string, int> hashMap, int wlen, int alen, int slen){
    for(int i = 0; i < alen; ++i){
        string str = s.substr(i * wlen, wlen);
        hashMap[str] -= 1;
        if(hashMap[str] < 0) return false;
    }
    return true;
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0) return vector<int>({});
        int wlen = words[0].size(), alen = words.size(), slen = s.size();
        if(alen * wlen > slen) return vector<int>({});
        cout<<wlen<<" "<<alen<<" "<<slen<<endl;
        unordered_map<string, int> hashMap;
        for(auto item = words.begin(); item != words.end(); ++item){
            if(hashMap.find(*item) == hashMap.end())
                hashMap[*item] = 1;
            else
                hashMap[*item] += 1;
        }

        vector<int> candidate;
        for(int i = 0; i < slen - wlen + 1; ++i){
            string thiss = s.substr(i, wlen);
            if(hashMap.find(thiss) != hashMap.end()){
                candidate.push_back(i);

            }
        }
        if(candidate.size() == 0) return vector<int>({});
        cout<<candidate.size()<<endl;

        vector<int> realCandidate={};
        for(int i = 0; i < candidate.size(); ++i){
            unordered_map<string, int> hashClone(hashMap);
            bool flag = true;
            for(int j = 0; j < alen; ++j){
                if(candidate[i] + j * wlen + wlen > s.size()){
                    flag = false;
                    break;
                }
                string thiss = s.substr(candidate[i] + j * wlen, wlen);
//                cout<<thiss<<" "<<i<<endl;
                if(hashClone.find(thiss) == hashClone.end()){
                    flag = false;
                    break;
                }
                hashClone[thiss] -= 1;
                if(hashClone[thiss] < 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                realCandidate.push_back(candidate[i]);
            }
        }
//        for(int i = 0; i < candidate.size() - alen + 1; ++i){
//            bool flag = true;
//            for(int j = 1; j < alen; ++j){
//                if(find(candidate.begin(), candidate.end(), candidate[i] + j * wlen) == candidate.end()){
//                    flag = false;
//                    break;
//                }
//            }
//            if(flag) {
//                if(check(s.substr(candidate[i], wlen * alen), hashMap, wlen, alen, slen))
//                    realCandidate.push_back(candidate[i]);
//            }
//        }

        return realCandidate;
    }
};

int main(){
    string s = "aaaaaa";
    vector<string> words = {"aaa", "aaa"};
    Solution s1;
    auto p = s1.findSubstring(s, words);

    for(auto item: p){
        cout<<item<<endl;
    }


    return 0;
}
