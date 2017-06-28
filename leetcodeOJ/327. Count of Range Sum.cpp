class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0)
            return 0;
        int n = countSum(nums, 0, nums.size()-1, lower, upper);
        return n;
    }
    
    int findIndex(vector<long long>& v, double val){
        int l = 0, r = v.size()-1, m = 0;
        while(l <= r){
            m = l + (r-l)/2;
            if(v[m] <= val)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
    
    int countSum(vector<int>& nums, int start, int end, int lower, int upper){
        if(start == end){
            if(nums[start] >= lower && nums[start] <= upper){
                //cout << start <<' ' << end << endl;
                return 1;
            }
            return 0;
        }
        
        int mid = start + (end-start)/2;
        vector<long long> v(end-mid, 0);
        long long sum = 0;
        for(int i = mid+1; i <= end; ++i){
            sum += nums[i];
            v[i-mid-1] = sum;
        }
        sort(v.begin(), v.end());
        
        int n1 = countSum(nums, start, mid, lower, upper);
        int n2 = countSum(nums, mid+1, end, lower, upper);
        int n3 = 0;
        sum = 0;
        for(int i = mid; i >= start; --i){
            sum += nums[i];
            n3 += findIndex(v, upper-sum+0.5) - findIndex(v, lower-sum-0.5);
        }
            
        return n1+n2+n3;
        
    }
    
    
};