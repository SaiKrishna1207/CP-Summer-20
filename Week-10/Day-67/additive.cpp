class Solution {
public:
    bool dfs(int idx, long long num1, long long num2, int l1, int l2, string &num) {
        if (num[idx] == '0')   
            return num1 + num2 == 0;
        int i;
        for (i = max(l1, l2); i <= max(l1, l2) + 1; i++) {
            long long cur = stoll(num.substr(idx, i));
            if (cur != num1 + num2)
                continue;
            if (idx + i == num.size())
                return true;
            if (dfs(idx + i, num2, cur, l2, i, num))
                return true;
        }
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        if(num.length() < 3)
            return false;
        int i, j, k;
        long long num1 = 0, num2 = 0;
        for (i = 1; 2 * i < num.size(); i++) {
            num1 = stoll(num.substr(0, i));
            for (j = 1; i + j + max(i, j) <= num.size(); j++) {
                num2 = stoll(num.substr(i, j));
                if (dfs(i + j, num1, num2, i, j, num))
                    return true;
                if (num[i] == '0')
                    break;
            }
        }
        return false;
    }
};