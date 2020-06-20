class Solution {
public:
   
    string getPermutation(int n, int k) {
       vector<int>vec;
        string name;
       while(n>0){
           vec.push_back(n);
           n--;
       }
      sort(vec.begin(),vec.end());
       while(k>1){
           next_permutation(vec.begin(),vec.end());
           k--;
       }
       for(int i=0;i<vec.size();i++){
           name+=(char)(vec[i]+48);
       }
        return name;
    }
};
