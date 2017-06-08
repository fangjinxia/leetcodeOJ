class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ans;
        map<int, set<int>> children;
        for(int i = 0; i < pid.size(); i++){
            children[ppid[i]].insert(pid[i]);
        }
        genAns(kill, children, ans);
        return ans;
    }
    
    void genAns(int kill, map<int, set<int>>& children, vector<int>&ans){
        ans.push_back(kill);
        for(int c : children[kill]){
            genAns(c, children, ans);
        }
        //return;
        
    }
};