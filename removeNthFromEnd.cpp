/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int length = 0;
    ListNode* temp = A;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    if(length == B || length < B) return A->next;
    length = length - B;
    temp = A;
    for(int i = 1;i<length;i++){
        temp = temp->next;  
    }
    temp->next = temp->next->next;
    return A;
}
