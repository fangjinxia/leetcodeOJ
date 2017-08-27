class Solution {
public:
    int pathSum(vector<int>& nums) {
        int arr[5][8] = {0};
        for(auto num : nums){
            int i = num / 100;
            int j = (num % 100) / 10 - 1;
            int v = num % 10;
            
            arr[i][j] = v + arr[i-1][j/2];
        }
        
        int sum = 0;
        for(int i = 1; i < 5; ++i){
            for(int j = 0; j < 8; ++j){
                if(i == 4 || arr[i][j] && !arr[i+1][j*2] && !arr[i+1][j*2+1])
                    sum += arr[i][j];
            }
        }
        
        return sum;
    }
};