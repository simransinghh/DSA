#include <list>
int diff(string A , string B){
    int count = 0;
    for(int i=0;i<A.size();i++){
        if(A[i]!=B[i]){
            count++;
        }
    }
    return count;
}
class graph{
  
  unordered_map<string,list<string>> adjList;
  
  public:
  graph(){}
  void add(string A, string B){
      int x = diff(A,B);
      if(x != 1) return;
      adjList[A].push_back(B);
      adjList[B].push_back(A);

  }
  void display(){
		for(auto node:adjList){
			cout<<node.first<<" -> ";

			for(auto val:node.second){
				cout<<val<<" ";
			}
			cout<<endl;
		}
	}

  
  int shortestPathBFS(string src , string dest){
		queue<string> q;
		unordered_map<string,int> dist;

		for(auto node:adjList){
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while(!q.empty()){

			string node = q.front();
			q.pop();

			for(string neighbor:adjList[node]){
				if(dist[neighbor]==INT_MAX){
					dist[neighbor] = dist[node] + 1;
					q.push(neighbor);
				}
			}
		}
        return dist[dest];
	}
};


int Solution::solve(string A, string B, vector<string> &C) {
    
    graph graph1;
    for(int i=0;i<C.size();i++){
        for(int j = i+1; j<C.size(); j++){
            graph1.add(C[i],C[j]);
        }
    }
    for(int i=0;i<C.size();i++){
         graph1.add(A,C[i]);
         graph1.add(B,C[i]);
    }
    // graph1.display();
    return graph1.shortestPathBFS(A,B) + 1;
}
