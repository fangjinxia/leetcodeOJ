class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<pair<int, int>> v;
        int minsum = INT_MAX;
        for(int i = 0; i < list1.size(); ++i){
            int idx = isExist(list2, list1[i]);
            if(idx == -1)
                continue;
            v.push_back(make_pair(i, idx+i));
            if(idx+i < minsum){
                minsum = idx+i;
            }
        }
        
        vector<string> res;
        for(auto x : v){
            if(x.second == minsum)
                res.push_back(list1[x.first]);
        }
        
        return res;
    }
    
    int isExist(vector<string>& list2, string s){
        for(int i = 0; i < list2.size(); ++i){
            if(s == list2[i])
                return i;
        }
        return -1;
    }
};