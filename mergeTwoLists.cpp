/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
     ListNode* head;
     if(A->val <= B->val){
         head = A;
         A = A->next;
     }else{
         head = B;
         B = B->next;
     }
    ListNode* curr = head;
     while(A != NULL && B!= NULL){
         if(A->val <= B->val){
            curr->next = A;
            curr = curr->next;
            A = A->next;
         }else{
            curr->next = B;
            curr = curr->next;
            B = B->next;
        }
     }
     if(A==NULL){
         curr->next = B;
     }
     else{
         curr->next = A;
     }

     return head;
}
