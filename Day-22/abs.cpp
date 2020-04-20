class Solution {
public:
    
    int mx(int a, int b)
    {
        if(a > b)
            return a;
        return b;
    }
    
    int mn(int a, int b)
    {
        if(a < b)
            return a;
        return b;
    }
    
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int i, j, amax, amin, bmax, bmin, cmax, cmin, dmax, dmin, a1, a3, a2, a4;
        int n = arr1.size();
        int a[n], b[n], c[n], d[n];
        for(i = 0;i < n; i++)
        {
            a[i] = arr1[i] + arr2[i] + i;
            b[i] = arr1[i] - arr2[i] + i;
            c[i] = arr1[i] + arr2[i] - i;
            d[i] = arr1[i] - arr2[i] - i;
        }
        amax = a[0]; amin = a[0];
        bmax = b[0]; bmin = b[0];
        cmax = c[0]; cmin = c[0];
        dmax = d[0]; dmin = d[0];
        for(i = 0;i < n; i++)
        {
            amax = mx(amax, a[i]);
            amin = mn(amin, a[i]);
            bmax = mx(bmax, b[i]);
            bmin = mn(bmin, b[i]);
            cmax = mx(cmax, c[i]);
            cmin = mn(cmin, c[i]);
            dmax = mx(dmax, d[i]);
            dmin = mn(dmin, d[i]);
        }
        a1 = amax - amin; a2 = bmax - bmin; a3 = cmax -cmin; a4 = dmax - dmin;
        int ans = mx(a1, mx(a2, mx(a3, a4)));
        return ans;
    }
        
};