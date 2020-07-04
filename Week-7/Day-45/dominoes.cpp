class Solution {
public:
    string pushDominoes(string dominoes) {
        int i, j, k;
        int n = dominoes.size();
        vector<int> v(n);
        for(i = 1; i < n; i++){
            if(dominoes[i - 1] == 'R' && dominoes[i] == '.'){
                dominoes[i] = 'R';
                v[i] = v[i - 1] + 1;
            }
        }

        for(i = n - 2; i >= 0; i--){
            if(dominoes[i + 1] == 'L'){
                j = v[i + 1] + 1;
                if(dominoes[i] == '.' || v[i] > j){
                    dominoes[i] = 'L';
                    v[i] = j;
                }
                else if(dominoes[i] == 'R' && v[i] == j){ // recover
                    dominoes[i] = '.';
                }
            }
        }
        return dominoes;
    }
};