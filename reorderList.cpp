ListNode* reverse(ListNode* h){
    ListNode* prev = NULL;
    ListNode* nxt = h->next;
    while(h->next != NULL){
       h->next = prev;
       prev = h;
       h = nxt;
       nxt = nxt->next;
    }
    h->next = prev;
    return h;
}
ListNode* Solution::reorderList(ListNode* A) {

    int length = 0;
    ListNode* temp = A;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    if(length<3) return A;
    temp =  A;
    for(int i = 1;i<length/2;i++){
        temp = temp->next;
    }
    ListNode* nn = temp;
    temp = temp->next;
    if(length%2 == 1){
        temp = temp->next;
        nn = nn->next;
    }
    ListNode* head = reverse(temp);
    nn->next = NULL;
    temp = A;
    while(head != NULL){
        ListNode* an = temp->next;
        ListNode* hn = head->next;
        temp->next = head;
        head->next = an;
        temp = an;
        head = hn;
    }
    return A;
}
