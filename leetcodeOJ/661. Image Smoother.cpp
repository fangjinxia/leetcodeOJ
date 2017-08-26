class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size();//����
        if(n == 0)
            return M;
        int m = M[0].size();//����
        if(n == 1 && m == 1)
            return M;
        
        vector<vector<int>> res(n, vector<int>(m, 0));
        
        int k = 0;
        int num = 0;
        for(int i = 0; i < n; ++i){            
            for(int j = 0; j < m; ++j){               
                //������
                if(i == 0 || i == (n-1) || j == 0 || j == (m-1)){
                    //�ĸ���
                    if(n == 1 || m == 1){
                        if((i == 0 || i == (n-1)) && (j == 0 || j == (m-1))){
                            k = 2;

                        }
                        else{//�������ϣ���ȥ�ĸ��ǵĽڵ�
                            k = 3;                        
                        }
                    }
                    else {   
                        if((i == 0 || i == (n-1)) && (j == 0 || j == (m-1))){
                            k = 4;

                        }
                        else{//�������ϣ���ȥ�ĸ��ǵĽڵ�
                            k = 6;                        
                        }
                    }
                                        
                }
                else{
                    k = 9;                                        
                }
                
                num = 0;
                for(int row = i-1; row <= i+1; ++row){
                    for(int loc = j-1; loc <= j+1; ++loc){
                        if(row < 0 || row >= n || loc < 0 || loc >= m)
                            continue;
                        num += M[row][loc]; 
                    }
                }
                res[i][j] = num / k;
            }
        }
        
        return res;
    }
};