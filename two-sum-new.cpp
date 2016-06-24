class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> rev;
        int gap;
        vector<int> ret;
        
        for (auto i=0; i<nums.size(); i++)
        {
            rev[nums[i]] = i;
        }

        for (auto i=0; i<rev.size(); i++)
        {
            gap = target - nums[i];
            if (rev.find(gap) != rev.end() && rev[gap] > i)
            {
                ret = {i,rev[gap]};  
                break;
            }
        }
        return ret;
    }

};