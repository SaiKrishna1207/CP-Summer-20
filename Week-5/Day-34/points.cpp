class Solution {
public:

    bool reachingPoints(int sx, int sy, int tx, int ty) {
        int i, j;
        if(tx == sx && ty == sy)
            return true;
        if(tx < sx || ty < sy)
            return false;
        while(tx > sx && ty > sy)
        {
            if(tx > ty)
                tx = tx%ty;
            else
                ty = ty%tx;
        }
        if(tx == sx)
        {
            if(ty >= sy && (ty - sy)%sx == 0)
                return true;
            return false;
        }
        if(ty == sy)
        {
            if(tx >= sx && (tx - sx)%sy == 0)
                return true;
            return false;
        }
        return false;
    }
};