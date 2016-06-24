class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        unordered_map<int,int> rev;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (auto i=0; i<nums.size(); i++)
        {
            rev[nums[i]] = i;
        }
        
        for (auto j=0; j<nums.size(); j++)
        {
            for (auto k=j+1; k<nums.size(); k++)
            {
                auto sum = 0 - (nums[j]+nums[k]);
                if (rev.find(sum) != rev.end() && rev[sum]>k)
                {
                    vector<int> v = {nums[j],nums[k],sum};
                    if (find(res.begin(),res.end(),v) == res.end())
                    {
                        res.push_back(v);
                    }
                }
            }
            
        }

        return res;
    }
};