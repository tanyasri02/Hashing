// approach 1: sort and just check the consecutive element=0(nlongn)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mx=1;
        int temp=1;
        if(nums.size()<1)
            return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==0)
                continue;
            if(nums[i]-nums[i-1]==1)
                temp++;
            else
            {
                temp=1;
            }
            mx=max(mx,temp);
        }
        return mx;
    }
};

// approach 2 : use set put all the elements of array into that and iterate over the array and check if next and element is present or not

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        
        for(auto it:nums)
            s.insert(it);
        
        int ans=0;
        
        for(auto it:nums)
        {
            if(!s.count(it-1))
            {
                int current=it;
                int c=1;
                
                while(s.count(current+1))
                {
                    c++;
                    current++;
                }
                ans=max(ans,c);
            }
        }
        
        return ans;
    }
};
