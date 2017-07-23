class Solution {
public:
    vector<string> ans;
    int n;
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        if(tickets.size() == 0)
            return ans;
        int n = tickets.size();
        
        unordered_map<string, multiset<string>> mp;
        for(auto item : tickets){
            mp[item.first].insert(item.second);
        }
        
        stack<string> st;
        st.push("JFK");
        while(!st.empty()){
            string airport = st.top();
            if(mp[airport].empty()){
                ans.push_back(airport);
                st.pop();
            }
            else{
                st.push(*(mp[airport].begin()));
                mp[airport].erase(mp[airport].begin());
                
            }
        }
                
        reverse(ans.begin(), ans.end());
        return ans;
    }
};