class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        for(int i=0;i<n+1;i++){
            dp[i]=0;
        }
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                  dp[i]= dp[i]+( dp[i-j]*dp[j-1]);  // 1 to i-1 left subtree and i+1 to n right subtree
            }
        }// so total number is the multiplication of left and right subtree 
        return dp[n];
    }
};
