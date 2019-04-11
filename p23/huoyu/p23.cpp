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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode *head=NULL;
        for(int i=0;i<lists.size();i++)
        {
            head=mergeTwoLists(head,lists[i]);
        }
        return head;
    }
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
      if(l1==NULL)
      {
          return l2;
      }
      else if(l2==NULL)
      {
          return l1;
      }
      else
      {
          ListNode *head=NULL;
          ListNode *temp=NULL;
          head=l1->val<=l2->val?l1:l2;
          temp=head;
          if(l1->val<=l2->val)
              l1=l1->next;
          else
              l2=l2->next;
          while(l1!=NULL&&l2!=NULL)
          {
              if(l1->val<=l2->val)
              {
                  temp->next=l1;
                  temp=temp->next;
                  l1=l1->next;
              }
              else
              {
                  temp->next=l2;
                  temp=temp->next;
                  l2=l2->next;
              }
          }
          if(l1==NULL)
          {
              temp->next=l2;
          }
          else
          {
              temp->next=l1;
          }
          return head;
      }
        }
};
