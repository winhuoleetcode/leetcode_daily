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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        if(head->next->next == NULL){
            ListNode *tmp = head->next;
            tmp->next = head;
            head->next = NULL;
            return tmp;
        }
        ListNode *cur = new ListNode(0);
        ListNode *root = cur;
        cur->next = head;
        ListNode *one = head, *two = head->next, *three = head->next->next;
        while(two != NULL && two->next != NULL){
            cur->next = two;
            two->next = one;
            one->next = three;

            ListNode *tmp = two;
            two = one;
            one = tmp;

            cur = cur->next->next;
            one = one->next->next;
            if(two->next->next == NULL){
                return root->next;
            }
            two = two->next->next;
            if(three->next->next == NULL){
                cur->next = two;
                cur->next->next = one;
                cur->next->next->next = NULL;
                return root->next;

            }
            three = three->next->next;

        }
        return root->next;
    }
};

int main(){
    Solution s;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);

    cout<<s.swapPairs(l1)->next->next->next->next->val<<endl;
    return 0;
}
