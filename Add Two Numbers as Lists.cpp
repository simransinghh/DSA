ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *d = new ListNode(-1);
    ListNode *tmp = d;
    int c = 0;
    while(A!=NULL or B!=NULL or c)
    {
    int sum = 0;
    if(A!=NULL)
    {
        sum=sum+A->val;
        A = A->next;
    }
    if(B!=NULL)
    {
        sum+=B->val;
        B = B->next;
    }
    sum+=c;
    c = sum/10;
    ListNode *node = new ListNode(sum%10);
    tmp->next = node;
    tmp = tmp->next;
    }
    return d->next;
}
