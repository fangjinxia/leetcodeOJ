class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        vector<int> F;
        int n = A.size();
        if(!n)
            return 0;
        int cur = 0;
        
        while(n--){
            int sum = 0;
            cur %= A.size();
            for(int i = 0; i < A.size(); i++){
                if(cur == A.size())
                    cur = 0;
                sum += cur * A[i];
                cur++;
            }
            cur++;
            F.push_back(sum);
        }
        
        int ans = *max_element(F.begin(), F.end());
        return ans;
    }
};