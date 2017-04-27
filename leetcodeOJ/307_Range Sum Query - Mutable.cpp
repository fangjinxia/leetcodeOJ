class NumArray {
public:
    NumArray(vector<int> nums) {
        accu = vector<int>(nums.size()+1, 0);
        for(int i = 1; i <= nums.size(); i++){
            accu[i] = nums[i-1];
        }
    }
    
    void update(int i, int val) {
        accu[i+1] = val;
    }
    
    int sumRange(int i, int j) {
        int k = 0;
        for(int idx = i+1; idx <= j+1; idx++){
            k += accu[idx];
        }
        return k;
    }
    
private:
    vector<int> accu;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */