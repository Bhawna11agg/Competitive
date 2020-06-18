class Solution {
public:
    int hIndex(vector<int>& citations) {
        for(int i=(citations.size()-1);i>=0;i--){
            if(((citations.size()-i)<=citations[i]) && (i==0 || (citations.size()-i)>=citations[i-1])){
                return citations.size()-i;
            }
        }
       return 0;
    }
};
