class Solution {
public:
    int gcd(int a, int b) 
    { 
        if (b == 0) 
            return a; 
        return gcd(b, a%b); 
    } 
    
    bool canMeasureWater(int x, int y, int z) {
        int i;
        if(z > x + y)
            return false;
        if(z == x || z == y || z == x + y)
            return true;
        i = gcd(x, y);
        if(z%i)
            return false;
        return true;
    }
};