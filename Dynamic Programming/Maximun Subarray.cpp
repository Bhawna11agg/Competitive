
//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count=0,min=INT_MIN;
        for(int i=0;i<nums.size();i++){
            count+=nums[i];
            if(count<0){
                count=0;
                continue;
            }
            if(count>min){
                min=count;
            }
        }
        if(min==INT_MIN)
        for(int i=0;i<nums.size();i++){
            if(min<nums[i]){
                min=nums[i];
            }
        }
        return min;
    }
};
