class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        ans[0] = 0;
        ans[1] = 1;
        int i = 2;
        while(i <= num){
            ans[i] = 1;
            for(int k = 1; k < i && ((k+i) <= num); k++){
                ans[i+k] = 1 + ans[k];
            }
            i *= 2;
        }
        
        return ans;
    }
};