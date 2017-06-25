class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<int> v1(0);
        vector<int> v2(0);
        for(auto x : arrays){
            v1.push_back(x[0]);
            v2.push_back(x[x.size()-1]);
        }
        int res = 0;
        int idx1 = min_element(v1.begin(), v1.end()) - v1.begin();
        int idx2 = max_element(v2.begin(), v2.end()) - v2.begin();
        //cout << idx1 << ' ' << idx2 << endl;
        if(idx1 != idx2)
            return v2[idx2] - v1[idx1];
        
        int tmp1 = INT_MAX;
        for(int i = 0; i < v1.size(); ++i){//找第二小的数
            if(i == idx1)
                continue;
            tmp1 = min(tmp1, v1[i]);
        }
        
        int tmp2 = INT_MIN;
        for(int i = 0; i < v2.size(); ++i){//找第二大的数
            if(i == idx1)
                continue;
            tmp2 = max(tmp2, v2[i]);
        }
        
        return max(v2[idx2]-tmp1, tmp2-v1[idx1]);
    }
};