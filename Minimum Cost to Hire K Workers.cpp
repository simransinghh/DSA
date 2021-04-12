class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        if(K==1){
            sort(wage.begin(), wage.end());
            return wage[0];
        }
        double ans = INT_MAX;
        double sum = INT_MAX;
        K--;
        int n = quality.size();
        for(int i=0;i<n;i++){
            double ratio = (wage[i]* 1.0)/(quality[i]* 1.0);
            priority_queue <double> maxHeap; 
            sum = wage[i];
            for(int j=0;j<n;j++){
                if(j==i) continue;
                double offer = quality[j]*ratio;
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
            if(maxHeap.size()==K){ans = min(ans,sum);}
        }
        return ans;
    }
};
