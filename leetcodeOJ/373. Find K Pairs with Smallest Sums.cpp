class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v(0);
        for(int i = 0; i < nums1.size(); ++i){
            for(int j = 0; j < nums2.size(); ++j){
                v.push_back(make_pair(nums1[i], nums2[j]));
            }
        }
        
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
            return (a.first+a.second) < (b.first+b.second);
        });
        
        if(k < nums1.size()*nums2.size()){
            vector<pair<int, int>> res(v.begin(), v.begin()+k);
            return res;
        }
        else
            return v;
    }
};