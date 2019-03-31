#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans;
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode *s1 = l1, *s2 = l2;
        if(s1->val < s2->val){
            ans = new ListNode(s1->val);
            s1 = s1->next;
        }else{
            ans = new ListNode(s2->val);
            s2 = s2->next;
        }

        ListNode *tmp = ans;

        while((s1 != NULL) && (s2 != NULL)){
            if(s1->val < s2->val){
                tmp->next = new ListNode(s1->val);
                s1  = s1->next;
                tmp = tmp->next;
            }else{
                tmp->next = new ListNode(s2->val);
                s2  = s2->next;
                tmp = tmp->next;
            }
        }
        if(s1 != NULL){
            while(s1 != NULL){
                tmp->next = new ListNode(s1->val);
                s1 = s1->next;
                tmp = tmp->next;
            }
        }
        if(s2 != NULL){
            while(s2 != NULL){
                tmp->next = new ListNode(s2->val);
                s2 = s2->next;
                tmp = tmp->next;
            }
        }
        return ans;
    }
};


int main(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode *ans = s.mergeTwoLists(l1, l2);
    cout<<ans->next->next->next->next->next->next->val<<endl;

}
