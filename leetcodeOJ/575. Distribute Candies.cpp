class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        vector<int> v(200002, 0);
        int cnt = 0;//糖的种类
        for(int i = 0; i < candies.size(); i++){
            if(v[candies[i]+100000] == 0){ //注意，存在负数
                v[candies[i]+100000] = 1;
                cnt++;
            }
        }
       // cout<<cnt<<endl;
        return (cnt >= (candies.size()>>1)) ? (candies.size()>>1) : cnt;
    }
};