
vector<vector<int> >Solution::generateMatrix(int A) {
    vector<vector<int>>vect;
    int j=1;
    int k=1;
    for(int i=0;i<A;i++){
        vector<int>vec;
        for(int j=0;j<A;j++){
            vec.push_back(-1);
        }
        vect.push_back(vec);
    }
    while(j<=A*A){
       for(int i=k-1;i<=A-k && j<=(A*A);i++){
         vect[k-1][i]=j;
         j++;
         if(j>A*A){
             break;
         }
       } 
       for(int i=k;i<=A-k && j<=(A*A);i++){
           vect[i][A-k]=j;
           j++;
            if(j>A*A){
             break;
         }
       }
       for(int i=A-k-1;i>=(k-1) && j<=(A*A);i--){
           vect[A-k][i]=j;
           j++;
            if(j>A*A){
             break;
         }
       }
       for(int i=A-k-1;i>=k && j<=(A*A);i--){
           vect[i][k-1]=j;
           j++;
            if(j>A*A){
             break;
         }
       }
       k++;
    }
    return vect;
}
