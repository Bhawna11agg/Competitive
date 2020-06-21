class Solution {
public:
    int Minimum(vector<vector<int>>&dungeon,int positivity,int borrow,int row,int col){ 
        if(row>=dungeon.size() || col>=dungeon[row].size()){
            return -1;
        }
       if((positivity+(dungeon[row][col]))<=0){
               borrow+=abs(positivity+dungeon[row][col])+1;
           positivity=1;
       }
        else{
            positivity=positivity + dungeon[row][col];
        }
       int horizontal= Minimum(dungeon,positivity,borrow,row,col+1);
       int vertical =Minimum(dungeon,positivity,borrow,row+1,col);
        if(horizontal==-1 && vertical==-1){
            return borrow;
        }
        if(horizontal==-1){
            return vertical;
        }
        if(vertical==-1){
            return horizontal;
        }
       int p= min(vertical,horizontal);
        return p;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int min1=Minimum(dungeon,0,0,0,0);
        if(min1==0){
            return 1;
        }
        else{
            return min1;
        }
    }
};



