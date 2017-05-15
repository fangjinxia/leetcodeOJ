class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        //≈≈–Ú
        sort(people.begin(), people.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first || ((a.first == b.first)&&(a.second < b.second));
        });
        
        vector<pair<int, int>> ans;
        for(int i = 0; i < people.size(); i++){
            ans.insert(ans.begin()+people[i].second, people[i]);
        }
        return ans;
    }
};