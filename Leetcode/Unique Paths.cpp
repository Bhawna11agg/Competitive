class Solution {
public:
    int uniquePaths(int m, int n) {
        int** arr=new int*[m];
        for(int i=0;i<m;i++){
            arr[i]=new int[n];
            for(int j=0;j<n;j++){
                arr[i][j]=1;
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 || j==n-1){
                    continue;
                }
               arr[i][j]=arr[i+1][j]+arr[i][j+1];
            }
        }
        return arr[0][0];
    }
};
