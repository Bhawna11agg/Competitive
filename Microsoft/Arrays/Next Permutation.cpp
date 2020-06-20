It is used to rearrange the elements in the range [first, last) into the next lexicographically greater permutation
like 1 2 3 to 1 3 2.

vector<int> Solution::nextPermutation(vector<int> &A) {
    int flag=0;
    vector<int> vect;
    if(next_permutation(A.begin(),A.end())){
        for(int i=0;i<A.size();i++){
            vect.push_back(A[i]);
        }
        flag=1;
    }
    if(flag==0){
      for(int i=0;i<A.size();i++){
            vect.push_back(A[i]);
        }  
    }
    return vect;
}
