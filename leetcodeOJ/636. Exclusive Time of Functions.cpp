class Solution {
public:
    struct LOG{
        int id;
        string status;
        int timestamp;
    };
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> time(n, 0);
        stack<LOG> st;
        for(string log : logs){
            stringstream ss(log);
            string tmp1, tmp2, tmp3;
            getline(ss, tmp1, ':');
            getline(ss, tmp2, ':');
            getline(ss, tmp3, ':');
            
            LOG item = {stoi(tmp1), tmp2, stoi(tmp3)};
            if(item.status == "start"){
                st.push(item);
            }
            else{
                assert(st.top().id == item.id);
                
                int k = item.timestamp - st.top().timestamp + 1;
                time[item.id] += k;
                st.pop();
                
                if(!st.empty()){
                    assert(st.top().status == "start");
                    time[st.top().id] -= k;
                }
            }
        }
        
        return time;
    }
};