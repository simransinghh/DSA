/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
     ListNode* temp = A;
     unordered_map<int,int> dup;
     while(temp != NULL){
        dup[temp->val]++;
        temp = temp->next;
    }
    while(A != NULL){
        if(dup[A->val]>1){
            A = A->next;
        }
        else{
            break;        
        }
    }
    if(A==NULL){
        return NULL;
    }
    temp = A;
    while(temp->next != NULL){
        if(dup[temp->next->val]>1){
            temp->next = temp->next->next;    
        }else{
            temp = temp->next;
        }
    }
    return A;
}
