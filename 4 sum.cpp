// ! apporach 1: sort + #3 nested loop (3 pointer) + binary search =0(n^3)
// For example : 1234533
//1. sort= 1233345
//2. i=0,j=1,k=3 3 loop 
//3. now from 4 to n apply binary search


// 2 ans better apporach that will be 0(n^2)
//1. sort + 2 loop + binary search
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int left=j+1;
                int right=n-1;
                
                int target2=target-nums[i]-nums[j];
                
                while(left<right)
                {
                    int rem_sum=nums[left]+nums[right];
                    
                    if(rem_sum<target2)
                        left++;
                    else if(rem_sum>target2)
                        right--;
                    else
                    {
                        vector<int>temp(4,0);
                        temp[0]=(nums[i]);
                        temp[1]=(nums[j]);
                        temp[2]=(nums[left]);
                        temp[3]=(nums[right]);
                        ans.push_back(temp);
                        
                        while(left<right && nums[left]==temp[2])
                            ++left;
                        while(left<right && nums[right]==temp[3])
                            --right;
                    }
                    
                }
                while(j+1<n && nums[j+1]==nums[j])
                        ++j;
            }
            while(i+1<n && nums[i+1]==nums[i])
                        ++i;
            
        }
        return ans;
    }
};
