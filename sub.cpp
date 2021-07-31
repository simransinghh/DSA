void countOfSubsets(int arr[], int N,
                    int K)
{
    int count = 0;
    int pre = 1;
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        if (arr[i] * pre >= K) {
            count++;
            pre = 1;
        }
        else {
            pre++;
        }
    }
 
    cout << count;
}
 
