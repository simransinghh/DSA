/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    int z=0,o=0;
    ListNode* temp=A;
    while(temp!=NULL){
        if(temp->val==0)z++;
        else o++;
        temp = temp->next;
    }
    temp = A;
    while(A!=NULL){
        if(z>0){
            A->val=0;
            z--;
        }
        else{
            A->val=1;
        }
        A=A->next;
    }
    return temp;
}

