int Solution::maxSpecialProduct(vector<int> &A) {
    vector<long int>left(A.size(),0);
    vector<long int>right(A.size(),0);
    stack<long int>st;
    if(A.size()<=2){
        return 0;
    }
    int j;
    for(int i=0;i<A.size();i++){
       while(!st.empty() && A[i]>A[st.top()]){
         left[st.top()]=i;
         st.pop();
       }
       st.push(i);
    }
      for(int i=A.size()-1;i>=0;i--){
       while(!st.empty() && A[i]>A[st.top()]){
         right[st.top()]=i;
         st.pop();
       }
       st.push(i); 
    }
    for(int i=0;i<A.size();i++){
        left[i]=(left[i]%1000000007)*(right[i]%1000000007);
    }
    sort(left.begin(),left.end());
    
    return left[A.size()-1]%1000000007;
}
