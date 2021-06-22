#include <bits/stdc++.h>
using namespace std;

    capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 

unordered_map<int,int> keyval;
unordered_map<int,list<int>::iterator> posinlist;
list<int> lruqueue;
int maxcap = 0;
int currcap = 0;
LRUCache::LRUCache(int capacity) {
    maxcap = capacity;
    lruqueue.clear();
    keyval.clear();
    posinlist.clear();
}

int LRUCache::get(int key) {
        auto it = keyval.find(key);
        if(it == keyval.end()) return -1;
        auto pt = posinlist.find(key);
        auto prevv = pt->second;
        prevv->next = prevv->next->next;
        lruqueue.push_front(key);
        posinlist[key] = lruqueue.begin();
        return it->second;
}

void LRUCache::set(int key, int value) {
        auto it = keyval.find(key);
        if(it != keyval.end()){
                it->second = value;
                auto pt = posinlist.find(key);
                auto prevv = pt->second;
                prevv->next = prevv->next->next;
                lruqueue.push_front(key);
                posinlist[key] = lruqueue.begin();
                return;
        } 
        if(maxcap == currcap){
                int k = lruqueue.end()->val;
                lruqueue.pop_back();
                keyval.erase(k);
                posinlist.erase(k);
        }
        lruqueue.push_front(key);
        posinlist[key] = lruqueue.begin();
        keyval[key] = val;
        return;
}
private: 
 unordered_map<int,int> keyval;
 unordered_map<int,list<int>::iterator> posinlist;
 list<int> lruqueue;
 int maxcap = 0;
 int currcap = 0;


vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    if(B>A.size())
        return ans;
    unordered_map<int,int> map;
    for(int i=0;i<B;i++){
        map[A[i]]++;
    }
    ans.push_back(map.size());
    for(int i=B;i<A.size();i++){
        int temp = A[i-B];
        map[temp]--;
        if(map[temp]==0){
             map.erase(temp);
             map[A[i]]++;
             ans.push_back(map.size());
        }
        else{
            map[A[i]]++;
            ans.push_back(map.size());
        }
    }
    return ans;
}


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
