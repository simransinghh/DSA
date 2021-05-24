ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A->next == NULL) return A;
    if(B==0) return A;
    ListNode* tempprev = NULL;
    ListNode* temp = A; 
    ListNode* templast = A; 
    for(int i = 1; i < B; i++){
        if(templast->next == NULL){
            return rotateRight(A,B%i);
        }
        templast = templast->next;
    }
    while(templast->next != NULL){
         tempprev = temp;
         templast = templast->next;
         temp = temp->next;
    }
    tempprev->next = NULL;
    templast->next = A;
    return temp;
}
