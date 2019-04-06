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

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
    ListNode *l1_start = l1, *l2_start = l2;
    if(l1_start == NULL && l2 == NULL) return NULL;
    if(l1_start == NULL) return l2;
    if(l2_start == NULL) return l1;
    while(l1_start->next != NULL && l2_start != NULL){
        if(l1_start->val <= l2_start->val){
            if(l1_start->next->val > l2_start->val){
                ListNode *tmp = l1_start->next;
                l1_start->next = new ListNode(l2_start->val);
                l1_start->next->next = tmp;
                l2_start = l2_start->next;
                l1_start = l1_start->next;
//                cout<<l2_start->val<<" "<<l1_start->val<<endl;
            }else{
                l1_start = l1_start->next;
            }
        }else{
            ListNode *tmp = new ListNode(l2_start->val);
            tmp->next = l1_start;
            l1_start = tmp;
            l1 = tmp;
            l2_start = l2_start->next;
        }
    }
    cout<<l1_start->next->val<<endl;

    if(l1_start->next == NULL){
        if(l2_start == NULL) return l1_start;
        if(l1_start->val > l2_start->val){
            while(l2_start->next != NULL && l2_start->next->val <= l1_start->val){
                l2_start = l2_start->next;
            }
            if(l2_start->next == NULL){
                l2_start->next = new ListNode(l1_start->val);
                return l2;
            }
            ListNode *tmp = l2_start->next;
            l2_start->next = new ListNode(l1_start->val);
            l2_start->next->next = tmp;
            return l2;
        }
        l1_start->next = l2_start;
        return l1;
    }
    return l1;

}


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        ListNode *ans = lists[0];
        for(int i = 1; i < lists.size(); ++i){
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<ListNode*> lists;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    lists.push_back(l1);
    ListNode *l2 = new ListNode(0);
    l2->next = new ListNode(2);
    lists.push_back(l2);
    ListNode *ans = s.mergeKLists(lists);
    cout<<ans->next->val<<endl;
    return 0;
}
