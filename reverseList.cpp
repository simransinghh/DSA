/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    if(A==NULL)
{
    return A;
}

ListNode* prev=NULL;
ListNode* curr=A;
ListNode* nxt;

int k=0;

while(curr!=NULL&&k<B)
{
    nxt=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nxt;
    k=k+1;
}
A->next=reverseList(curr,B);
return prev;
}
