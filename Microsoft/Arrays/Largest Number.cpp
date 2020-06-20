#include<algorithm>
bool comp(string A,string B){
    string X=A.append(B);
    string Y=B.append(A);
    return X.compare(Y)>0 ?1:0;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string>vect;
    for(int i=0;i<A.size();i++){
    string name1="";
    int b=A[i];
    while(b>0){
        name1=(char)((b%10)+48)+name1;
        b=b/10;
    }
    if(name1.length()!=0)
    vect.push_back(name1);
  }
  if(vect.size()==0){
      return "0";
  }
  sort(vect.begin(),vect.end(),comp);
  string name="";
   for(int i=0;i<vect.size();i++){
    name=name+vect[i];
   }
    return name;
}
