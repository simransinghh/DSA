/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* big = NULL;
    ListNode* small = NULL;
    ListNode* temp = A;
    bool bf = false;
    bool sf = false;
    while(temp != NULL){
        if(temp->val >= B && !bf){
            big = temp;
            bf = true;
        }
        if(temp->val < B && !sf){
            small = temp;
            sf = true;
        }
        if(bf && sf) break;
        temp = temp->next;
    }
    temp = A->next;
    ListNode* btemp = big;
    ListNode* stemp = small;
    while(temp != NULL){
        if(temp == btemp){ 
            temp = temp->next;
            continue;
        }
        if(temp == stemp) { 
            temp = temp->next;
            continue;
        }
        if(temp->val >= B){
            btemp->next = temp;
            btemp = btemp->next;
        }
        if(temp->val < B){
            stemp->next = temp;
            stemp = stemp->next;
        }
        temp = temp->next;
    }
    if(small == NULL){
        btemp->next = NULL;
        return big;
    }
    if(big == NULL){
        stemp->next = NULL;
        return small;
    }
    stemp->next = big;
    btemp->next = NULL;
    return small;
}
