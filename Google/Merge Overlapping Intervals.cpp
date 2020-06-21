/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp(Interval A,Interval B){
     if(A.start<B.start){
         return true;
     }
     return false;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval>vect;
    sort(A.begin(),A.end(),comp);
    int index=0;
    for(int i=1;i<A.size();i++){
      if(A[i].start<=A[index].end){
          A[index].end=max(A[i].end,A[index].end);
          A[index].start=min(A[i].start,A[index].start);
      }
     else{
         vect.push_back(A[index]);
         index=i;
         flag=1;
         continue;
     }
    }
        vect.push_back(A[index]);  
   return vect; 
}
