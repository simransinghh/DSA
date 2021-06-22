#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode* head = A[0],temp;
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



vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>res;
    priority_queue <int, vector<int>, greater<int> > pq;
    sort(A.begin(), A.end(),greater<int>()); 
    sort(B.begin(), B.end(),greater<int>());
    int x = 0;
    for(int i=0; i<A.size(); i++) {
            for(int j = 0;j<B.size();j++){
                int sum  = A[i]+B[j];
                if(x==C){
                        if(sum > pq.top()){
                                pq.pop();
                                pq.push(sum);
                        }
                        else break;
                }
                else{
                      pq.push(sum);  
                      x++;
                }
            }
    }
    for(int i = 0;i<C;i++){
            res.push_back(pq.top());
            pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int Solution::nchoc(int n, vector<int> &v){
    priority_queue<int> pq;

    for(int i=0;i<v.size();i++)
    {
        pq.push(v[i]);
    }
    long long sum=0;

    while(n>0)
    {
        int temp=pq.top();
        int num=pq.top();
        sum=(sum+num);
        pq.pop();
        pq.push(num/2);
        n--;
}
    int temp=sum%1000000007;
    return temp;
}
int main() {
    int A =
    vector<int> C =
    vector<int> ans
    cout<<ans[0]<<ans[1];
}
