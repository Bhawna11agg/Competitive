"https://leetcode.com/problems/unique-paths-ii/submissions/"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         long long int** arr=new  long long int*[obstacleGrid.size()];
        for(int i=obstacleGrid.size()-1;i>=0;i--){
            arr[i]=new long long int[obstacleGrid[i].size()];
            for(int j=0;j<obstacleGrid[i].size();j++){
                arr[i][j]=0;
            }
        }
  for(int i=obstacleGrid.size()-1;i>=0;i--){
      for(int j=obstacleGrid[i].size()-1;j>=0;j--){
              if(i==obstacleGrid.size()-1 ||  j==obstacleGrid[i].size()-1){
            if(i!=obstacleGrid.size()-1){
                if((arr[i+1][j]!=0 && obstacleGrid[i][j]!=1))
                  arr[i][j]=1;
                  continue;
              }
          if( j!=obstacleGrid[i].size()-1){
              if(arr[i][j+1]!=0 && obstacleGrid[i][j]!=1)
                  arr[i][j]=1;
                  continue;
          }
                   if(obstacleGrid[i][j]!=1)
                    arr[i][j]=1;
                     continue;
              }
           if(obstacleGrid[i][j]!=1){
              arr[i][j]=arr[i+1][j]+arr[i][j+1];
          } 
      }
  }
        return arr[0][0];
    }
};
