class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size()<3)
        {
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        cout<<"+++++++++ target: "<<target<<"  +++++++++++++++++++"<<endl;
        cout<<"[";
        for (auto a:nums)
        {
            cout<<a<<", ";
        }
        cout<<"]"<<endl;
        
        int left,right,sums;
        auto last = nums.end();
        left = right = nums[0]+nums[1]+nums[2];
        
        for (auto i = nums.begin(); i < last -2 ; ++i)
        {
            auto j = i + 1;
            auto k = last -1;
            auto mid = j + (k-j+1)/2;
            while(j<k)
            {
                if(*i + *j + *k < target)
                {
                    sums = *i + *j + *k;
                    if(left < target)
                    {
                        left = max(sums,left);
                    }else
                    {
                        left = sums;
                    }
                    cout<<"    left: "<<left<<"( i:"<<*i<<" j: "<<*j<<" k: "<<*k<<" )"<<endl;
                    while(*j == *(j - 1) && j < k) 
                        ++j;
                    mid = j + (k-j+1)/2;
                    if (*i + *mid + *k < target)
                    {
                        j = mid;
                        mid = j + (k-j+1)/2;
                    }else
                    {
                        ++j;
                    }
                    cout<<"J:"<<*j<<endl;
                }else if (*i + *j + *k > target)
                {
                    sums = *i + *j + *k;
                    if(right>target)
                    {
                        right = min(sums,right);
                    }else
                    {
                        right = sums;
                    }
                    cout<<"    right: "<<right<<"( i:"<<*i<<" j: "<<*j<<" k: "<<*k<<" )"<<endl;
                    while((*k == *(k - 1)) && j < k) 
                        --k;
                    cout<<"1 K:"<<*k<<endl;
                    mid = j + (k-j)/2;    
                    if (*i + *j + *mid > target)
                    {
                        k = mid;
                        cout<<"2 K:"<<*k<<endl;
                        mid = j + (k-j)/2;
                    }else
                    {
                        --k;
                        cout<<"3 K:"<<*k<<endl;
                    }
                    cout<<"K:"<<*k<<endl;
                    
                }else
                {
                    sums = *i + *j + *k;
                    cout<<"--- Jump --- sum: "<<sums<<" target: "<<target<<endl;
                    return target;
                }
                cout<<endl;
            }
 
        }
        cout<<"--- left: "<<left<<" right: "<<right<<" ---"<<endl;
        if(abs(target-left) > abs(target-right))
        {
            sums = right;
        }else
        {
            sums = left;
        }
        cout<<"--- Final --- sum: "<<sums<<" target: "<<target<<endl;
        return sums;
        
    }
};