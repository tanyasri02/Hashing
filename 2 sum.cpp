class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        
        unordered_map<int,int>mp;
            
        
        for(int i=0;i<nums.size();i++)
        {
            int temp=target-nums[i];
            if(mp[temp]>0)
            {
                return {i,mp[temp]-1};
            }
            mp[nums[i]]=i+1;
        }
        
        return {};
    }
};
