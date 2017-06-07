class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //某一个点到另外三个点的距离
        int dist12 = (p1[0]-p2[0]) * (p1[0]-p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1]);
        int dist13 = (p1[0]-p3[0]) * (p1[0]-p3[0]) + (p1[1]-p3[1]) * (p1[1]-p3[1]);
        int dist14 = (p1[0]-p4[0]) * (p1[0]-p4[0]) + (p1[1]-p4[1]) * (p1[1]-p4[1]);
        if(dist12 == 0 || dist13 == 0 || dist14 == 0)
            return false;
        //找p1的对角点
        int m = max(max(dist12, dist13), dist14);
        if(m == dist12){
            if(dist13 != dist14 || dist12 != 2*dist13)
                return false;
            
            int dist23 = (p2[0]-p3[0]) * (p2[0]-p3[0]) + (p2[1]-p3[1]) * (p2[1]-p3[1]);
            int dist24 = (p2[0]-p4[0]) * (p2[0]-p4[0]) + (p2[1]-p4[1]) * (p2[1]-p4[1]);
            if(dist23 == 0 || dist24 == 0)
                return false;
            if(dist23 != dist24 || dist12 != 2*dist23)
                return false;
        }
        else if(m == dist13){
            if(dist12 != dist14 || dist13 != 2*dist12)
                return false;
            
            int dist32 = (p2[0]-p3[0]) * (p2[0]-p3[0]) + (p2[1]-p3[1]) * (p2[1]-p3[1]);
            int dist34 = (p3[0]-p4[0]) * (p3[0]-p4[0]) + (p3[1]-p4[1]) * (p3[1]-p4[1]);
            if(dist32 == 0 || dist34 == 0)
                return false;
            if(dist32 != dist34 || dist13 != 2*dist32)
                return false;
        }
        else {
            if(dist12 != dist13 || dist14 != 2*dist12)
                return false;
            
            int dist42 = (p2[0]-p4[0]) * (p2[0]-p4[0]) + (p2[1]-p4[1]) * (p2[1]-p4[1]);
            int dist43 = (p3[0]-p4[0]) * (p3[0]-p4[0]) + (p3[1]-p4[1]) * (p3[1]-p4[1]);
            if(dist42 == 0 || dist43 == 0)
                return false;
            if(dist42 != dist43 || dist14 != 2*dist42)
                return false;
        }
        return true;
    }
};