bool isPossible(vector<vector<char>> &A, int r, int c, int k){
    char ch = k + '0';
    for(int i = 0;i < 9; i++){
        if(A[r][i] == ch)
            return false;
        if(A[i][c] == ch)
            return false;
    }
    int rs, re, cs, ce, i, j;
    int k1 = r / 3;
    int k2 = c / 3;
    switch(k1){
        case 0 :rs = 0;
                break;
        case 1 :rs = 3;
                break;
        case 2 :rs = 6;
                break;
    }
    switch(k2){
        case 0 :cs = 0;
                break;
        case 1 :cs = 3;
                break;
        case 2 :cs = 6;
                break;
    }
    re = rs + 3;
    ce = cs + 3;
    for(i = rs; i < re; i++){
        for(j = cs; j < ce; j++){
            if(A[i][j] == ch)
                return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &A, int r, int c){
    if(r == 9)
        return true;
    if(c == 9)
        return solve(A, r + 1, 0);
    if(A[r][c] != '.')
        return solve(A, r, c + 1);
    int i;
    for(i = 1;i <= 9; i++){
        if(isPossible(A, r, c, i)){
            A[r][c] = '0' + i;
            if(solve(A, r, c + 1))
                return true;
            
            A[r][c] = '.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    int i, j;
    if(A.size() != 9 || A[0].size() != 9)
        return;
    solve(A, 0, 0);
}
