ListNode* Solution::subtract(ListNode* A) {

        ListNode* temp = A;
        ListNode* tail = A;
        int n = 0;
        while(tail->next != NULL){
                n++;
                tail = tail->next;
        }
        n++;
        cout<<n<<endl;
        if(n==1 || n==0) return A;
        int i = 1;
        ListNode* tt = NULL;
        ListNode* prev = NULL;
        while(i <= n){
            cout<<i<<endl;
            ListNode* newprev = NULL;
                if(i <= n/2){ 
                        prev = temp;
                        cout<<i<<"->"<<temp->val<<"  ";
                        temp = temp->next;
                }
                else if(i==n/2 && n%2!=0){
                    prev = temp;
                    cout<<i<<"->"<<temp->val<<"  ";
                    temp = temp->next;
                }
                else{
                    cout<<temp->val<<" "<<temp->next->val<<" "<<prev->val<<endl;
                      if(temp->next->next != NULL){
                              tt = temp->next->next;
                              newprev = temp->next;
                              temp->next->next = temp;
                              temp->next = prev;

                      }else if(temp->next == NULL){
                              temp->next = prev;
                              break;
                      }else{
                              newprev = temp->next;
                              temp->next = prev;
                              newprev->next = temp;
                              break;
                      }
                    cout<<temp->val<<" "<<temp->next->val<<" "<<prev->val<<endl;
                    i++;
                    temp = tt;
                    prev = newprev;
                    cout<<temp->val<<" "<<temp->next->val<<" "<<prev->val<<endl;
                    cout<<"-----------------------"<<endl;
                }
                i++;
        }
        i = 1;
        temp = A;
        prev = NULL;
        tt = NULL;
        while(i<=n/2){
            cout<<temp->val;
            temp->val = tail->val - temp->val;
            cout<<temp->val<<" "<<temp->next->val<<" "<<prev->val<<endl;
            temp = temp->next;
            tt = tail->next;
            tail->next = prev;
            prev = tail;
            tail = tt;
            i++;
            cout<<temp->val<<" "<<temp->next->val<<" "<<prev->val<<" "<<i<<endl;
        }
        if(temp==tail){
                temp->next = prev;
        }
        return A;

}
