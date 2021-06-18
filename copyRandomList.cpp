RandomListNode* Solution::copyRandomList(RandomListNode* head) {
unordered_map<RandomListNode*,RandomListNode*> mp;
RandomListNode *curr = head, *clone;
while(curr){
    RandomListNode *t = new RandomListNode(curr->label);
    mp[curr] = t;
    curr = curr->next;
}
curr = head;
while(curr){
    clone = mp[curr];
    clone->next = mp[curr->next];
    clone->random = mp[curr->random];
    curr = curr->next;
}
return mp[head];
}
