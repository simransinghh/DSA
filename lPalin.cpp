 ListNode* reverse(ListNode* head){
      ListNode* temp = head;
      ListNode* prev = NULL;
      ListNode* nextt = head->next;
      while(nextt != NULL){
          temp->next = prev;
          prev = temp;
          temp = nextt;
          nextt = temp->next;
      }
      temp->next = prev;
      return temp;
 }
bool issame(ListNode* a,ListNode* b){
    while(a != NULL){
        if(a->val != b->val){
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}
// 6 -> 3 -> 7 -> 3 -> 6
int Solution::lPalin(ListNode* A) {
    int length = 0;
    ListNode* temp = A;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    if(length == 1){
        return true;
    }
    temp = A;
    for(int i = 1;i<length/2;i++){
        temp = temp->next;  
    }
    ListNode* end = temp;
    temp = temp->next;
    if(length%2 == 1){
        ListNode* end2 = temp;
        temp = temp->next;
        end2->next = NULL;
    }
    end->next = NULL;
    ListNode* head = reverse(temp);

    return issame(A,head);
    
}
