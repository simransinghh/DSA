ListNode* Solution::detectCycle(ListNode* A) {
    unordered_map<ListNode*,bool> vis;
    vis.insert({A,true});
    ListNode* temp = A->next;
    while(temp != NULL){
        if(vis.find(temp) != vis.end()){
            return temp;
        }
        vis.insert({temp,true});
        temp = temp->next;
    }
    return temp;
}
