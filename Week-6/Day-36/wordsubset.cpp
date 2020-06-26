class Solution {
public:
    
    int isUniversal(vector<int> bl, string a){
        int i, j = 0;
        vector<int> al(26, 0);
        for(i = 0; i < a.length(); i++)
            al[a[i] - 97]++;
        for(i = 0; i < 26; i++){
            if(al[i] >= bl[i])
                j++;
        }
        if(j == 26)
            return 1;
        return 0;
    }
    
    vector<int> ret(string a){
        int i, j;
        vector<int> ans(26, 0);
        for(i = 0;i < a.length(); i++)
            ans[a[i] - 97]++;
        return ans;
    }
    
    vector<int> convert(vector<string> B){
        int i, j, k;
        vector<int> c(26, 0);
        for(i = 0;i < B.size(); i++){
            vector<int> cur = ret(B[i]);
            for(j = 0;j < 26; j++)
                c[j] = max(c[j], cur[j]);
        }
        return c;
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int i, j, k;
        if(!B.size() || !A.size())
            return {};
        vector<string> ans;
        vector<int> b = convert(B);
        // for(i = 0;i < 26; i++)
        //     cout << b[i] << " ";
        for(i = 0; i < A.size(); i++){
            if(isUniversal(b, A[i]))
                ans.push_back(A[i]);
        }
        return ans;
    }
};