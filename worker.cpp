#include <bits/stdc++.h>
using namespace std;
double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        
        double ans = INT_MAX;
        double sum = INT_MAX;
        K--;
        int n = quality.size();
        for(int i=0;i<n;i++){
            int ratio = wage[i]/quality[i];
            priority_queue <int> maxHeap; 
            for(int j=0;j<n;j++){
                if(j==i) continue;
                int offer = quality[j]*ratio;
                if(offer < wage[j]){
                    continue;
                }
                if(maxHeap.size()<K){
                    maxHeap.push(offer);
                    sum += offer;
                }else{
                    if(maxHeap.top()>offer){
                        sum = sum + offer - maxHeap.top();
                        maxHeap.pop();
                        maxHeap.push(offer);
                    }
                }                
            }
            ans = min(ans,sum);
        }
        return ans;
}

int main()
{
    vector<int> quality = {10,20,5}; 
    vector<int> wage = {70,50,30};
    int K=2;
    cout<<mincostToHireWorkers(quality,wage,K);
    return 0;
}
