int Solution::solve(ListNode* A, int B) {
    int length = 0;
    ListNode* temp = A;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    length = length/2 +1 - B;
    if(length < 1) return -1;
    temp = A;
    for(int i=1;i<length;i++){
        temp = temp->next;
    }
    return temp->val;
}
