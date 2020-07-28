class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        int i, j, k;
        if(n > 1)
            return 0.5;
        else
            return 1;
    }
};