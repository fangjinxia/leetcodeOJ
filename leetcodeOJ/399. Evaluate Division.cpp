class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> m;
        vector<double> res;
        for(int i = 0; i < values.size(); i++){
            m[equations[i].first].insert(make_pair(equations[i].second, values[i]));
            if(values[i] != 0)
                m[equations[i].second].insert(make_pair(equations[i].first, 1/values[i]));
        }
        
        for(auto query : queries){
            unordered_set<string> s;
            double tmp = check(query.first, query.second, m, s);
            if(tmp)
                res.push_back(tmp);
            else
                res.push_back(-1);
        }
        
        return res;
    }
    
private:
    double check(string fst, string sec, unordered_map<string, unordered_map<string, double>>& m, unordered_set<string>& s){
        if(m[fst].find(sec) != m[fst].end())
            return m[fst][sec];
        
        for(auto f : m[fst]){
            if(s.find(f.first) == s.end()){
                s.insert(f.first);
                double tmp = check(f.first, sec, m, s);
                if(tmp)
                    return f.second * tmp;
            }
        }
        
        return 0;
    }
};