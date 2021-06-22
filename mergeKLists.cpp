ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode* head = A[0];
    ListNode* temp;
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i = 0;i<A.size();i++){
            if(i>0) temp->next = A[i];
            temp = A[i];
            while(temp->next != NULL){
                    pq.push(temp->val);
                    temp = temp->next;
            }
            pq.push(temp->val);
    }
    temp = head;
    while(temp != NULL){
            temp->val = pq.top();
            pq.pop();
            temp = temp->next;
    }
    return head;
}
