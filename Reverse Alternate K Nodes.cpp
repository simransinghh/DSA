/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
    if(A==NULL||A->next==NULL) return A;
    ListNode* head=new ListNode(-1);
    head->next=A;
    ListNode* t;
    ListNode* p1=head;
    ListNode* p2=A;
    ListNode* pre1=head;
    ListNode* pre2=A;
    int count=0;
    bool rev=true;
    while(p1!=NULL&&p2!=NULL){
        if(rev){
            t=p2->next;
            p2->next=p1;
            p1=p2;
            p2=t;
            count++;
            if(count==B){
                pre1->next=p1;
                pre2->next=p2;
                count=0;
                rev=false;
            }
        }
        else{
            t=p2->next;
            p1=p2;
            p2=t;
            count++;
            if(count==B){
                pre1=p1;
                pre2=p2;
                count=0;
                rev=true;
            }
        }
    }
    return head->next;
}
