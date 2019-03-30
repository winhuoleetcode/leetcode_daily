#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
   ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp   = head;
        ListNode *start = head;
        for(int i = 0; i < n; ++i){
            if(tmp->next == NULL){
                // delete first one
                ListNode *ans = start->next;
                return ans;
            }
            tmp = tmp->next;
        }
        while(tmp->next != NULL){
            tmp = tmp->next;
            start = start->next;
        }
        start->next = start->next->next;
        return head;
   }
};


int main(){
    Solution s;
    ListNode *start = new ListNode(1);
    start->next = new ListNode(2);
    start->next->next = new ListNode(3);
    start->next->next->next = new ListNode(4);
    start->next->next->next->next = new ListNode(5);
    ListNode *ans = s.removeNthFromEnd(start, 2);
    cout<<ans->next->next->val<<endl;



    return 0;
}
