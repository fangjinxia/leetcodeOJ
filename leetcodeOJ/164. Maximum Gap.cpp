class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
            
        //Í°ÅÅÐò
        for(int i = 0; i < 31; ++i){
            vector<int> v1(0);
            vector<int> v0(0);
            int tmp = 1 << i;
            for(int j = 0; j < nums.size(); ++j){
                //cout << (nums[j]&tmp) << endl;
                if((nums[j]&tmp) != 0){
                    v1.push_back(nums[j]);
                }
                else{
                    v0.push_back(nums[j]);
                }
            }
            
            int s = v0.size();
            for(int k = 0; k < s; ++k){
                nums[k] = v0[k];
            }
            for(int k = 0; k < v1.size(); ++k){
                nums[s+k] = v1[k];
            }
        }
        
        // for(int i = 0; i < nums.size(); ++i){
        //     cout << nums[i] << endl;
        // }
        
        int res = 0;
        for(int i = 1; i < nums.size(); ++i){
            res = max(res, nums[i]-nums[i-1]);
        }
        
        return res;
    }
};