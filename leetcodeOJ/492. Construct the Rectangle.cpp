class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2);
        int w = sqrt(area);
        if(w*w == area){
            ans[0] = w;
            ans[1] = w;
            return ans;
        }
        while(1){
            int l = area/w;
            if(w*l == area){
                ans[0] = l;
                ans[1] = w;
                break;
            }
            w--;
        }
        return ans;
    }
};