#include <bits/stdc++.h>
using namespace std;
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
    vector<vector<string>> dfs(string src , string dest , vector<string> &dict , int level ,unordered_map<string,int> &visited , bool &found){
    vector<vector<string>> finall;
    if(level == 1 && src == dest ){
        found = true;
        vector<string> q;
        q.push_back(dest);
        finall.push_back(q);
        return finall;
    }
    if(level == 1 && src != dest ){
        return finall;
    }
    visited[src] = 1;
    // cout<<src<<endl;
    for(auto node : adjList[src]){
        if(visited[node] != 1){
            vector<vector<string>> x =  dfs(node,dest,dict,level-1,visited,found);
            // for(int i = 0; i<x.size(); i++) {
            //     for(int j = 0; j<x[i].size(); j++) {
            //         cout << '(' << x[i][j] << ")";
            //     }
            //     cout << "\n";
            // }

            if(found){
                for(int i=0;i<x.size();i++){
                    x[i].insert(x[i].begin(), src);
                    finall.push_back(x[i]);
                }
                found = false;
            }
        }
    }

    // for(int i = 0; i<finall.size(); i++) {
    //     for(int j = 0; j<finall[i].size(); j++) {
    //         cout << '(' << finall[i][j] << ")";
    //     }
    //     cout << "\n";
    // }    
    return finall;
    }
};



vector<vector<string>> findLadders(string A, string B, vector<string> &C) {
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
    int min = graph1.shortestPathBFS(A,B) + 1;
    unordered_map<string,int> visited;
    bool found = false;
    vector<vector<string>> s = graph1.dfs(A , B , C , min ,visited ,found);
    return s;
 
}

int main() {
    vector<string> C = {"hot", "dot", "dog", "lot", "log"};
    vector<vector<string>> s = findLadders("hit", "cog" , C);
    for(int i = 0; i<s.size(); i++) {
        for(int j = 0; j<s[i].size(); j++) {
            cout << '(' << s[i][j] << ")";
        }
        cout << "\n";
    }
    return 0;
}
