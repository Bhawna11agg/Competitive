class Solution {
public:
    int chone(int** arr,int start,int* visited,int n){
        int count=0;
        for(int i=0;i<n;i++){
            if(i==start){
                continue;
            }
            if(arr[start][i]==1){
                count++;
            }
        }
        return count;
    }
    bool check(int** arr,int start,int* visited,int N){
        for(int i=0;i<N;i++){
            if(i==start){
                continue;
            }
            if(arr[i][start]!=1){
                return false;
            }
        }
        return true;
    }
    int findJudge(int N, vector<vector<int>>& trust) {
        int** arr=new int*[N];
        for(int i=0;i<N;i++){
            arr[i]=new int[N];
            for(int j=0;j<N;j++){
                arr[i][j]=-1;
            }
        }
        for(int i=0;i<trust.size();i++){
            arr[trust[i][0]-1][trust[i][1]-1]=1;
        }
        int* visited=new int[N];
        for(int i=0;i<N;i++){
            visited[i]=0;
        }
        for(int i=0;i<N;i++){
            int c=chone(arr,i,visited,N);
            if(c==0){
                if(check(arr,i,visited,N)){
                    return i+1;
                }
            }
        }
                   return -1;
    }
};
