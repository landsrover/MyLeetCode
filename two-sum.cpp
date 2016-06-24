class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        if (sum_cache.empty())
        {
            for (auto i = 0; i < nums.size(); i++)
            {
                for (auto j = i+1; j < nums.size(); j++)
                {
                    auto key = nums[i]+nums[j];
                    sum_cache[key] = {i,j};
                }
            }
        }
        return sum_cache[target];
    }
    
private:
    unordered_map<int,vector<int>> sum_cache; 
};



