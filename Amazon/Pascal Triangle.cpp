vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>>vect;
     if(A==0){
       return vect; 
    }
    vector<int>vec;
    vec.push_back(1);
    vector<int>vec1;
    vec1.push_back(1);
    vec1.push_back(1);
    vect.push_back(vec);
    if(A==1){
        return vect;
    }
    vect.push_back(vec1);
    for(int i=2;i<A;i++){
        vector<int>vec;
        vec.push_back(1);
        for(int j=0;j<vect[i-1].size()-1;j++){
            int a=vect[i-1][j]+vect[i-1][j+1];
            vec.push_back(a);
        }
        vec.push_back(1);
        vect.push_back(vec);
    }
    return vect;
}
