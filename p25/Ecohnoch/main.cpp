#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
//  one two  three
//p<-1<-2     3  -> 4 -> 5 -> 6 -> 7
//      one  two   three

//p<-1<-2<-   3    4  -> 5 -> 6 ->7


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *realHead = new ListNode(0);
        realHead->next = head;
        ListNode *lenTmp = head, *pre = realHead, *now = realHead->next;
        int lenn = 0;
        while(lenTmp != NULL) {lenn ++; lenTmp = lenTmp->next;}
        while(lenn >= k){
            ListNode *nowBack = now;
            ListNode *cur = now->next;
            ListNode *n = cur->next;
            for(int i = 0; i < k - 1; ++i){
                n = cur->next;
                cur->next = now;
                now = cur;
                cur = n;
            }

            pre->next = now;
            nowBack->next = cur;

            pre = nowBack;
            now = cur;
            lenn -= k;

        }
        return realHead->next;
    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    ListNode *ans = s.reverseKGroup(head, 4);
    cout<<ans->next->next->next->next->next->next->next->next->val<<endl;



    return 0;
}
