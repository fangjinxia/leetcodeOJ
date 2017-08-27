class Solution {
public:
    //1, k+1, 2, k, 3, k-1 ...;
    //The distance of this sequence is k, k-1, k-2, ..., 2, 1
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int lo = 1;
        int hi = k+1;
        while(lo < hi){
            res.push_back(lo++);
            res.push_back(hi--);
        }
        if(lo == hi)
            res.push_back(lo);
        for(int i = k+2; i <= n; ++i){
            res.push_back(i);
        }
            
        return res;
    }
};