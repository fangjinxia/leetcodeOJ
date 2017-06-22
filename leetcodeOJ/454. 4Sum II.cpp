class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.size() < 1)
            return 0;
        
        unordered_map<int, int> m;
        for(auto a : A){
            for(auto b : B){
                ++m[a+b];
            }
        }
        
        int res = 0;
        for(auto c : C){
            for(auto d : D){
                int target = 0 - c - d;
                auto it = m.find(target);
                if(it != m.end())
                    res += it->second;
            }
        }
        
        return res;
    }
};