/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head=NULL;
        ListNode* r=NULL;
        bool first=true;
        int a=0;
        int sum=0;
        while(l1!=NULL||l2!=NULL)
        {
            if(l1!=NULL&&l2!=NULL)
            {
                sum=l1->val+l2->val+a;
                if(sum>9)
                {
                    a=1;
                    sum=sum-10;
                }
                else
                {
                    a=0;
                } 
            }
            if(l1!=NULL&&l2==NULL)
            {
                sum=l1->val+a;
                if(sum>9)
                {
                    a=sum-9;
                    sum=sum-10;
                }
                else
                {
                    a=0;
                } 
            }
            if(l1==NULL&&l2!=NULL)
            {
                sum=l2->val+a;
                if(sum>9)
                {
                    a=sum-9;
                    sum=sum-10;
                }
                else
                {
                    a=0;
                } 
            }
            
            if(first)
            {
                r=new ListNode(sum);
                head=r;
                first=false;
            }
            else
            {
                r->next=new ListNode(sum);
                r=r->next;
            }
            if(l1&&l1->next)
            {
               l1=l1->next; 
            }
            else
            {
                l1=NULL;
            }
            if(l2&&l2->next)
            {
               l2=l2->next; 
            }
            else
            {
                l2=NULL;
            }
            
        }
        if(a!=0)
        {
            r->next=new ListNode(a);
                r=r->next;
            
        }
        return head;
        
    }
};