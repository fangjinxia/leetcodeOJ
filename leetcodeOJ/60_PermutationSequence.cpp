class Solution {
public:
    string getPermutation(int n, int k) {
        ///<˼·����Ϊǰ(n-1)!�����еĵ�һ����ĸ��1���ڶ���(n-1)!�����еĵ�һ����ĸ��2����������
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