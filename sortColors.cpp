void Solution::sortColors(vector<int> &A) {
    int left=0, mid=0, right=A.size()-1;
    while(mid<=right)
    {
        if(A[mid]==0)
        {
            swap(A[left++], A[mid++]);
        }
        else if(A[mid]==2)
        {
            swap(A[mid], A[right--]);
        }
        else mid++;
    }
}
