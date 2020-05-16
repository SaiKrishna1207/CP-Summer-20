class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int i, j, k;
        long long area1 = abs((C - A) * (D - B));
        long long area2 = abs((H - F) * (G - E));
        long long areaover;
        if(E > C || F >= D || H <= B || G <= A)
            return area1 + area2;
        else
        {
            int xmin = max(A, E);
            int ymin = max(F, B);
            int xmax = min(C, G);
            int ymax = min(D, H);
            areaover = abs((xmax - xmin) * (ymax - ymin));
        }
        return area1 + area2 - areaover;
    }
    
};