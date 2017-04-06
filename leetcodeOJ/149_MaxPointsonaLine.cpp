/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 //˼·�����㼸�����⣬����һЩ�㼯��������һ��ֱ���ϵ����㣬
 //û�뵽ɶ�ð취��n���㣬һ��n*(n-1)��ֱ�ߣ���ѭ�����У��ص���������ж�һ����ֱ����
 //ע��߽������һЩϸ�ڣ�����n=1,n=2
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int max = 0;
        int n = points.size();
        if(n == 0 || n == 1 || isAllSame(points))
            return n;
        
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                    continue;
                int temp = 2;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j)
                        continue;
                    //С�����
                    if(((long)(points[k].y - points[i].y) * (long)(points[j].x - points[i].x)) == ((long)(points[k].x - points[i].x) * (long)(points[j].y - points[i].y))){//�ж�k����ֱ��ij��
                        temp++;
                    }
                }
                max = (temp > max) ? temp : max;
                
            }
        }
        return max;
    }
    
private:
    bool isAllSame(vector<Point>& points){
        //���еĵ㶼һ��
        for(int i = 1; i < points.size(); i++){
            if(points[i].x != points[0].x || points[i].y != points[0].y)
                return false;
        }
        return true;
    }
};
