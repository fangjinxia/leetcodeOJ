class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do{
            if(isValid(nums))
                return true;
        }while(next_permutation(nums.begin(), nums.end()));
        
        return false;
    }
    
    bool isValid(vector<int>& nums){
        double a = nums[0];
        double b = nums[1];
        double c = nums[2];
        double d = nums[3];
        
        if(isValid(a+b, c, d) || isValid(a, b+c, d) || isValid(a, b, c+d))
            return true;
        if(isValid(a-b, c, d) || isValid(a, b-c, d) || isValid(a, b, c-d))
            return true;
        if(isValid(a*b, c, d) || isValid(a, b*c, d) || isValid(a, b, c*d))
            return true;
        if(isValid(a/b, c, d) || isValid(a, b/c, d) || isValid(a, b, c/d))
            return true;
        
        return false;
    }
    
    bool isValid(double a, double b, double c){
        if(isValid(a+b, c) || isValid(a, b+c))
            return true;
        if(isValid(a-b, c) || isValid(a, b-c))
            return true;
        if(isValid(a*b, c) || isValid(a, b*c))
            return true;
        if(b&&isValid(a/b, c) || c&&isValid(a, b/c))
            return true;
        
        return false;
    }
    
    bool isValid(double a, double b){
        if(isValid(a+b) || isValid(a-b) || isValid(a*b) || b&&isValid(a/b))
            return true;
        
        return false;
    }
    
    bool isValid(double a){
        if(abs(a - 24.0) < 0.00001)
            return true;
        
        return false;
    }
};