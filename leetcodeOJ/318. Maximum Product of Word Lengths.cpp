class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(), 0);
        int res = 0;
        for(int i = 0; i < words.size(); ++i){
            for(auto c : words[i]){
                mask[i] |= 1 << (c-'a');
            }
            for(int j = i-1; j >= 0; --j){
                if(!(mask[i] & mask[j]))
                    res = max(res, int(words[i].size()*words[j].size()));
            }
        }
        
        return res;
    }
};