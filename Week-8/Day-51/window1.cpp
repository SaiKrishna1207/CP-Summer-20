bool check(unordered_map<char, int>& mp, unordered_map<char, int>& ss){
    for(auto i : mp){
        if(ss[i.first] < i.second)
            return false;
    }
    return true;
}


string Solution::minWindow(string A, string B) {
    int i = 0, j = 0, k;
    if(B.length() > A.length())
        return "";
    unordered_map<char, int> subl, a;
    for(i = 0; i < B.length(); i++)
        subl[B[i]]++;
    string ans = "";
    k = INT_MAX;
    i = 0;
    while(j < A.length()){
        a[A[j]]++;
        j++;
        if(check(subl, a)){
            while(check(subl, a)){
                a[A[i]]--;
                i++;
            }
            if(j - i + 1 < k){
                k = j - i + 1;
                ans = A.substr(i - 1, j - i + 1);
            }
        }
    }
    return ans;
}
