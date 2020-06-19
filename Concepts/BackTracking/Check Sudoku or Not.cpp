
bool check(int board[][9],int start,int end,int k){
   for(int i=0;i<9;i++){
       if(board[start][i]==k){
           return 0;
       }
   }
     for(int i=0;i<9;i++){
       if(board[i][end]==k){
          // cout<<board[i][end]<<i;
           return 0;
       }
   }
    int k1=start/3;
    int p=end/3;
    for(int i=k1*3;i<(k1+1)*3;i++){
        for(int j=p*3;j<(p+1)*3;j++){
            if(board[i][j]==k){
                return 0;
            }
        }
    }
    board[start][end]=k;
    return 1;
}
bool sudoku(int board[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                for(int k=1;k<10;k++){
                    if(check(board,i,j,k)){
                        if(sudoku(board)){
                            return true;
                        }
                        board[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool sudokuSolver(int board[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!=0){
                int p=board[i][j];
                board[i][j]=0;
                if(!check(board,i,j,p)){
                   return false; 
                }
            }
        }
    }
    return sudoku(board);
}
   
