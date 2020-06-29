#include<unordered_map>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>map;
         for(int i=0;i<nums.size();i++){
             map[nums[i]]=i;
         } 
        unordered_map<int,int>:: iterator it;
        int index1=0,total=0;
        for(it=map.begin();it!=map.end();it++){
            int k=1,sum=1,index;
            while(map.count(it->first+k)!=0 && map[it->first+k]!=-1){
                map[it->first+k]=-1;
                sum++;
                if(map[it->first+k]<index){
                    index= map[it->first+k];
                }
                k++;
            }
            k=1;
            while(map.count(it->first-k)!=0 && map[it->first-k]!=-1){
                map[it->first-k]=-1;
                sum++;
                 if(map[it->first-k]<index){
                    index= map[it->first-k];
                }
                k++;
            } 
            if(total<=sum){
                total=sum;
                if(index<index1){
                    index1=index;
                }
            }
        }
        return total;
    }
};
