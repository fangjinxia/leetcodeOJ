class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a1 = (C-A)*(D-B);
        int a2 = (G-E)*(H-F);
        int row = 0, col = 0;
        if(E >= A && E < C)
            row = min(C, G) - E;
        else if(E < A && G > A)
            row = min(G, C) - A;
        
        if(H <= D && H > B)
            col = H - max(B, F);
        else if(H >= D && F < D)
            col = D - max(B, F);
        int a3 = row*col;
        
        return a1+a2-a3;
    }
};