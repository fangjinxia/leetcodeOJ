class Solution {
public:
    int reverse(int x) {
        int flag = 0;//�ж�x�Ƿ�Ϊ����flagΪ0ʱĬ��Ϊ����
        if(abs(x) != x){
            flag = 1;
            x = abs(x);
        }

        long long ans = 0;
        while(x){
            ans = ans * 10 + x % 10;
            x /= 10;
        }

        if(ans < INT_MIN || ans > INT_MAX){
            return 0;
        }
        return (flag == 0)? ans : (0-ans);
    }
};
