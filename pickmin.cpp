int Graph::pickMinimum(int *dist,bool *mstSet){
    int min_index=-1;
    int min_distance=INT_MAX;
    int i;
    for(i=0;i<n;i++){
          if(dist[i]<min_distance&&mstSet[i]==false){
            min_index=i;
            min_distance=dist[i];
          }
    }
return min_index;
}

void Graph:: MSTPrim(){
    int *parent = new int[n];
    int *dist = new int[n];
    bool *mstSet = new bool[n];

    for(int i=0;i<n;i++){
        mstSet[i]=false;
        dist[i] = INT_MAX;
    }

    dist[0]=0;
    parent[0]=-1;


    int u;
    //Pick one vertex everytime. 0th already picked.
    for(int i=0;i<n-1;i++){

        int u=this->pickMinimum(dist,mstSet);
        mstSet[u]=true;
        for(int j=0;j<n;j++){
                //NOte this PART ! DONT CONFUSE WITH DIJKSHTRA's
            if(adj[u][j]&&mstSet[j]==false&&adj[u][j]<dist[j]){
                dist[j]=adj[u][j];
                parent[j]=u;
            }
        }
    }
    cout<<"Vertext - Distance - Parent "<<endl;
    for(int i=0;i<n;i++){
            cout<<i<<" ,"<<dist[i]<<" ,"<<parent[i]<<endl;
        }


}
