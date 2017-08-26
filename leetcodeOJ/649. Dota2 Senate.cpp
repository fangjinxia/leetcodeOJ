class Solution {
public:
    string predictPartyVictory(string senate) {
        //˼·������Rʱ��ɾ�������D������Dʱ��ɾ�������R��ѭ��
        queue<int> q1, q2;
        int n = senate.length();
        for(int i = 0; i < n; ++i){
            if(senate[i] == 'R')
                q1.push(i);
            else
                q2.push(i);
        }
        
        while(!q1.empty() && !q2.empty()){
            int idx1 = q1.front();
            int idx2 = q2.front();
            q1.pop();
            q2.pop();
            (idx1 > idx2) ? q2.push(idx2+n) : q1.push(idx1+n);
        }
        return (q1.size() > q2.size()) ? "Radiant" : "Dire";
    }
    
};