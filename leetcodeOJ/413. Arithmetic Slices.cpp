class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2)
            return 0;
        
        int ans = 0;
        int tmp = 0;
        for(int i = 2; i < A.size(); i++){
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
                tmp++;
            else{
                ans += (tmp*(tmp+1)/2);
                tmp = 0;
            }
        }
        ans += (tmp*(tmp+1)/2);
        return ans;
    }
};