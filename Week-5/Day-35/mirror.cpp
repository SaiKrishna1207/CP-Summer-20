class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(p == q)
            return 1;
        if(p%q == 0)
        {
            int a = p / q;
            if(a%2)
                return 1;
            return 2;
        }
        int gd = __gcd(p, q);
        p = (p / gd)%2;
        q = (q / gd)%2;
        if(p == 1 && q == 1)
            return 1;
        if(p == 1)
            return 0;
        return 2;
    }
};