class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int idx = s.length() - 2;
        for(; idx >= 0; idx--){
            if(s[idx] < s[idx+1])
                break;
        }
        if(idx < 0)
            return -1;
            
        vector<char> v(s.length());
        copy(s.begin(), s.end(), v.begin());
        int k = idx+1;
        for(int i = idx+2; i < v.size(); i++){
            if(v[i] > v[idx])
                k = (v[i] < v[k]) ? i : k;
        }
        //交换s[idx]与s[k]
        char temp = v[idx];
        v[idx] = v[k];
        v[k] = temp;
        
        //将idx+1到end进行排序
        sort(v.begin()+idx+1, v.end());
        
        //将vector转换为int型
        long long ans = 0;
        for(int i = 0; i < v.size(); i++){
            ans *= 10;
            ans += v[i]-'0';
        }
        if(ans > INT_MAX)
            return -1;
        return (int)ans;
    }
};