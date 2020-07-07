vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int>map;
    for(int i=0;i<B;i++){
        if(map.count(A[i])==0){
            map[A[i]]=1;
        }
        else{
            map[A[i]]++;
        }
    }
    int count=0;
    vector<int>vec;
    unordered_map<int,int>:: iterator it;
    for(it=map.begin();it!=map.end();it++){
        count++;
    }
    vec.push_back(count);
    
    for(int i=B;i<A.size();i++){
        map[A[i-B]]--;
         if( map[A[i-B]]==0){
          count--;
      }
        map[A[i]]++;
      if(   map[A[i]]==1){
          count++;
      }
         vec.push_back(count);
   
    }
    return vec;
}
