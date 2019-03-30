        ListNode *temp=head;
        vector<ListNode *> ans_list;
        while(temp)
        {
            ans_list.push_back(temp);
            temp=temp->next;
        }
        int aim=ans_list.size()-n;
        if(ans_list.size()==1&&n==1)
        {
            return NULL;
        }
        if(aim-1>=0&&aim+1<ans_list.size())
        {
          ans_list[aim-1]->next=ans_list[aim+1];  
        }
        else if(aim==0)
        {
            head=head->next;
        }
        
        
        //delete ans_list[aim];
        return head;