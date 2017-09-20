class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> mp;
    
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(mp.find(key) == mp.end()){
            mp.insert(make_pair(key, val));
        }
        else
            mp[key] = val;       
    }
    
    int sum(string prefix) {
        map<string, int>::iterator it;
        int len = prefix.length();
        int res = 0;
        for(it = mp.begin(); it != mp.end(); ++it){
            string s = it->first;
            if(s.length() < len)
                continue;
            else{
                if(s.substr(0, len) == prefix)
                    res += it->second;
            }
        }
        
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */