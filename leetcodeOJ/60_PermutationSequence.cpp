class Solution {
public:
    string getPermutation(int n, int k) {
        ///<思路：因为前(n-1)!的排列的第一个字母是1，第二个(n-1)!的排列的第一个字母是2，依次类推
        string ans = "";
        int mul = 1;
        for(int i = 1; i < n+1; i++){
            mul *= i;  ///<n!
            ans += to_string(i);///<"1234...n"
        }
        k--;
        for(int i = 0; i < n; i++){
            mul = mul/(n-i); 
            int j = i + k/mul;
            char temp = ans[j];
            for(; j > i; j--){
                ans[j] = ans[j-1];
            }
            ans[i] = temp;
            k %= mul;
            
        }
        
        return ans;
    }

};