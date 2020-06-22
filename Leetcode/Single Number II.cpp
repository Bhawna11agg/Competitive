#include<unordered_map>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<long int,int>map;
        for(long int i=0;i<nums.size();i++){
           if(map.count(nums[i])==0){
               map[nums[i]]=1;
           } 
            else{
                map[nums[i]]++;
            }
        }
        unordered_map<long int,int>:: iterator it;
        for(it=map.begin();it!=map.end();it++){
            if(it->second==1){
                return it->first;
            }
        }
        return -1;
    }
};
