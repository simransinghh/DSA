void merge(vector<int> &A, vector<int> &B) {
   auto dxa = A.begin();
   auto dxb = B.begin();
   while(dxa != A.end() || dxb != B.end()){
       if(*dxa>*dxb){
           A.insert(dxa,*dxb);
           dxa = dxa+1;
           dxb = dxb+1;
       }
       else{
           dxa = dxa + 1;
       }
       if(dxb == B.end()) return;
   }
   while(dxb != B.end()){
       A.push_back(*dxb);
       dxb=dxb+1;
   }  
   return;
}
