class Solution {
public:
    int arrangeCoins(int n) {
      long long int  count=0,j=0;
       while(1){
          count=count+(j+1);
          if(count>n){
              return j;
          }
           j++;
       }
        return 0;
    }
};
