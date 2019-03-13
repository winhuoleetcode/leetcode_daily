#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        int c = 0;

        int tmp_val = l1->val + l2->val;
        if(tmp_val >= 10){
            ans = new ListNode(tmp_val - 10);
            c = 1;
        }else{
            ans = new ListNode(tmp_val);
            c = 0;
        }

        ListNode *l1_tmp = l1->next, *l2_tmp = l2->next, *ans_tmp = ans;
        while((l1_tmp != NULL) && (l2_tmp != NULL)){
            int tmp_val = l1_tmp->val + l2_tmp->val + c;
            if(tmp_val >= 10){
                ans_tmp->next = new ListNode(tmp_val - 10);
                c = 1;
            }else{
                ans_tmp->next = new ListNode(tmp_val);
                c = 0;
            }
            cout<<l1_tmp->val<<" "<<l2_tmp->val<<endl;

            l1_tmp  = l1_tmp->next;
            l2_tmp  = l2_tmp->next;
            ans_tmp = ans_tmp->next;
        }

        if(l2_tmp != NULL){
            l1_tmp = l2_tmp;
        }

        if(l1_tmp != NULL){
            while(l1_tmp != NULL){
                int tmp_val = l1_tmp->val + c;
                if(tmp_val >= 10){
                    ans_tmp->next = new ListNode(tmp_val - 10);
                    c = 1;
                }else{
                    ans_tmp->next = new ListNode(tmp_val);
                    c = 0;
                }
                l1_tmp  = l1_tmp->next;
                ans_tmp = ans_tmp->next;
            }
        }

        if(c == 1){
            ans_tmp->next = new ListNode(1);
        }


        cout<<ans->val<<endl;
        cout<<ans->next->val<<endl;
        cout<<ans->next->next->val<<endl;


        return ans;
    }
};

//int main(){
//    Solution s;
//    ListNode *p, *p2;
//    p             = new ListNode(2);
//    p->next       = new ListNode(4);
//    p->next->next = new ListNode(3);

//    p2       = new ListNode(5);
//    p2->next = new ListNode(6);
//    p2->next->next = new ListNode(4);

//    ListNode *ans = s.addTwoNumbers(p, p2);
//    return 0;
//}
