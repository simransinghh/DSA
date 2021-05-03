#include <bits/stdc++.h>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

 struct comp{
    bool operator()(const Interval &x ,const Interval &y){
        if(x.start==y.start){
            return x.end < y.end;
        }
        return x.start < y.start;
    }
};
vector<Interval> merge(vector<Interval> &A) {
    sort(A.begin(),A.end(),comp());
    for(int i=0;i<A.size();i++){
        if(A[i+1].start<A[i].end && A[i+1].end<A[i].end){
            A.erase(A.begin()+i+1);
            i--;
            
        }
        else if(A[i+1].start<A[i].end){
            A[i].end = A[i+1].end;
            A.erase(A.begin()+i+1);
            i--;
        }
        if(A.size()==1){
            return A;
        }
    }

    return A;
  
}



int main() {
    vector<Interval>a;
    Interval q(1, 10);
    Interval w(2, 9);
    Interval e(3, 8);
    Interval r(4, 7); 
    Interval t(5, 6);
    Interval y(6, 6);
    a.push_back(q);
    a.push_back(w);
    a.push_back(e);
    a.push_back(r);
    a.push_back(t);
    a.push_back(y);
    vector<Interval> z = merge(a);
    for (auto i =0; i < z.size(); ++i)
        cout << z[i].start << " "<<z[i].end;
}
