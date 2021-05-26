ListNode* Solution::reverseBetween(ListNode* A, int B, int C)
{
if(A==NULL)return A;
ListNode* back=A;
ListNode* front=A;
int count1=1;int reverse_size=C-B;
while(front && count1<B)
{ count1++;
back=front;
front=front->next;
}

//reversing
ListNode* i=front;
ListNode* j=front->next;
ListNode* k= front->next;
int count=0;
 while(k && count<reverse_size )
 {
     k=j->next;
     j->next=i;
     i=j;
     j=k;
     count++;
} 

if(k==NULL&& count1==1){front->next=NULL;return i;}
if(count1==1 && k!=NULL)
{
    front->next=j;return i;
}
back->next=i;
front->next=j;
return A;
}
