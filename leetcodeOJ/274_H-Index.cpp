class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for(int i = n; i > 0; i--){
            if(i == n){
                if(citations[0] >= n)
                    return n;
            }
            else if(citations[n-i] >= i && citations[n-i-1] <= i)
                return i;
        }
        return 0;
    }
};