class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
            return ;
        vector<int> v(nums);
        sort(v.begin(), v.end());
        int idx = 0;
        int i = (nums.size()%2 == 0) ? (nums.size()/2-1) : nums.size()/2;
        int k = i;
        int j = nums.size()-1;
        for(; i >= 0 || j > k; ){
            if(idx % 2 == 0)
                nums[idx++] = v[i--];
            else
                nums[idx++] = v[j--];
            //cout << idx << endl;
            
        }
    }
};