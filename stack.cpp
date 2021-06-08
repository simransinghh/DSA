	Stack(int capacity = 10){
		this->capacity = capacity;
		arr = new int[this->capacity];
		top = -1;
	}

	int size(){
		return top+1;
	}

	bool empty(){
		return size()==0;
	}

	int last(){
		if(empty()){
			cout<<"Stack is empty"<<endl;
			return -1;
		}

		return arr[top];
	}

	void push(int data){
		if(size()==capacity){
			cout<<"Stack is full"<<endl;
			return;
		}

		arr[++top] = data;
	}

	void pop(){
		if(empty()){
			cout<<"Stack is empty"<<endl;
			return;
		}

		top--;
	}
};
