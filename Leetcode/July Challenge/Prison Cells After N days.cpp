#include<unordered_map>
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int>arr;
        vector<vector<int>>vec;
        for(int i=0;i<8;i++){
            arr.push_back(0);
        }
        int p=N;
        vec.push_back(cells);
       for(int m=1;m<=N;m++){
             arr[0]=0;
             arr[7]=0;
            for(int i=1;i<7;i++){
              if(cells[i-1]==cells[i+1]){
                  arr[i]=1;
              }
            else{
                  arr[i]=0;
              }
            }
             for(int i=0;i<8;i++){
                    cells[i]=arr[i];
                 cout<<cells[i];
              }
           cout<<endl;
           if(N>1000)
             for(int i=0;i<vec.size();i++){
                 if(arr==vec[i]){
                    p=vec.size()-i;
                    N=(N-m)%p;
                    cout<<N<<i;
                    if(N==0){
                        return vec[i];
                    }
                     if(i+N<vec.size())
                    return vec[i+N];
                     else
                    return vec[vec.size()-i-N+1];
                 }
             }
            vec.push_back(arr);
         }
        return arr;
    }
};
