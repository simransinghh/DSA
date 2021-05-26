ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *start = new ListNode(0);
    ListNode *head = A;
    start->next = head;
    ListNode *i = head, *prev = start;
    
    while(i != NULL){
        if(i->next && (i->val > i->next->val)){
            while(prev->next && (prev->next->val < i->next->val)) prev = prev->next;
            //insert btw prev and prev->next
            ListNode *temp = prev->next;
            prev->next = i->next;
            i->next = i->next->next;
            prev->next->next = temp;
            prev = start;
        } else {
            i = i->next;
        }
    }
    return start->next; 
    
}
