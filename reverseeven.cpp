ListNode* Solution::solve(ListNode* A) {

vector<int>vec;

ListNode * temp = A;
while(temp!=NULL)
{
    vec.push_back(temp->val);
    temp=temp->next;
}

int n = vec.size();
// ListNode * ans = new ListNode

ListNode * temp1= A;
if(n%2==0)
{
for(int i=1;i<n/2;i+=2)
{
swap(vec[i],vec[n-i]);
}

     int i=0;
    while(temp1!=NULL)
    {
        temp1->val = vec[i];
        i++;
        temp1=temp1->next;
    }
}
else
{
    for(int i=1;i<n/2;i+=2)
    {
        swap(vec[i],vec[n-i-1]);
    }
    
    int i=0;
    while(temp1!=NULL)
    {
        temp1->val = vec[i];
        i++;
        temp1=temp1->next;
    }
    
}

return A;
}
