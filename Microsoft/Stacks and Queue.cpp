vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int>stack;
      vector<int>B;
      if(A.size()==0){
        return B;
    }
    stack.push(A[0]);
     B.push_back(-1);
    for(int i=1;i<A.size();i++){
        while(stack.size()>0){
            if(stack.top()>=A[i]){
              stack.pop();
            }
            else{
                B.push_back(stack.top());  
                break;
            }
        } 
             if(stack.size()==0)
               B.push_back(-1);
              stack.push(A[i]);
    }
    return B;
}
