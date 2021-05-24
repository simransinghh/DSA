int Solution::kthsmallest(const vector<int> &A, int B) {
    priority_queue<int> heap;
    for (int i = 0; i < A.size(); i++) {
        heap.push((-1) * A[i]);
    }
    for(int i=0;i<B-1;i++)
        heap.pop();
    return (heap.top()) * (-1);
}
