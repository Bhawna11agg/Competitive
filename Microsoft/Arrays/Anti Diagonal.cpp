vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>>B;
    for(int i=0;i<A.size();i++){
        vector<int>vec;
        vec.push_back(A[0][i]);
        int k=i,h=0;
        while(k-1>=0 && h+1>=0){
            vec.push_back(A[h+1][k-1]);
            k--;
            h++;
        }
        B.push_back(vec);
    }
    for(int i=1;i<A.size();i++){
       vector<int>vec;
       int k=A.size()-1,h=i;
       vec.push_back(A[i][A.size()-1]);
       while(k-1<A.size() && h+1<A.size()){
         vec.push_back(A[h+1][k-1]);
            k--;
            h++;  
       }
        B.push_back(vec);
    }
    return B;
}
