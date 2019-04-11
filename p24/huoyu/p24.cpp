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
    ListNode* swapPairs(ListNode* head) {
     ListNode *temp1=head;
     ListNode *temp2=NULL;
     ListNode *temp=head;
     if(temp1!=NULL&&head->next!=NULL)
     {
         temp2=head->next;
         head=temp2;
     }
     while(temp1!=NULL&&temp2!=NULL)
     {
         
         temp1->next=temp2->next;
         temp2->next=temp1;
         if(temp2!=head)
         {
             temp->next=temp2;
             temp=temp1;   
         }
         temp1=temp1->next;
         if(temp1!=NULL&&temp1->next!=NULL)
         {
             temp2=temp1->next;
         }
         else 
         {
            temp2=NULL;
         }
     }
     return head;
    }
};