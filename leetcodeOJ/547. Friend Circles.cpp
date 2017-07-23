
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> v(n, 0);
        if(n == 0)
            return 0;
        
        //≥ı ºªØ
        for(int i = 0; i < n; ++i){
            v[i] = i;
        }
        
        int group = n;
        for(int i = 0; i < n-1; ++i){
            for(int j = i+1; j < n; ++j){
                if(M[i][j]){
                    int parent_i = find(i, v);
                    int parent_j = find(j, v);
                    if(parent_i != parent_j){
                        v[parent_i] = parent_j;
                        --group;
                    }
                }
            }
        }
        
        return group;
    }
    
    int find(int k, vector<int>& v){
        return k == v[k] ? k : find(v[k], v);
    }
};