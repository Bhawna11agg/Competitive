"https://leetcode.com/problems/single-number-iii/submissions/"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>vec;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                vec.push_back(nums[i]);
            }
            else{
                i++;
            }
        }
        if(vec.size()==1){
            vec.push_back(nums[nums.size()-1]);
        }
        return vec;
    }
};
