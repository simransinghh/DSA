Queue(int maxSize){
		this->maxSize = maxSize;
		arr = new int[maxSize];
		front = 0;
		back = -1;
		currSize = 0;
	}

	bool isFull(){
		return currSize==maxSize;
	}

	bool empty(){
		return currSize==0;
	}

	int size(){
		return currSize;
	}

	int getFront(){
		return arr[front];
	}

	void push(int data){
		if(isFull()){
			cout<<"Queue is full"<<endl;
			return;
		}

		back = (back+1)%maxSize;
		arr[back] = data;
		currSize++;
	}

	void pop(){
		if(empty()){
			cout<<"Queue is empty"<<endl;
			return;
		}

		front = (front+1)%maxSize;
		currSize--;
	}
