
int kadaneAlgo(int arr[],int n){

	int max_sub = arr[0];
	int global_max = arr[0];

	for(int i=1;i<n;i++){

		max_sub = max(max_sub+arr[i],arr[i]);

		if(max_sub>global_max){
			global_max = max_sub;
		}
	}

	return global_max;
}
