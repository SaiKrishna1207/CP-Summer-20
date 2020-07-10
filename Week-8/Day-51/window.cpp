bool check(unordered_map<char, int> mp, string s){
    unordered_map<char, int> ss;
    for(int i = 0; i < s.length(); i++)
        ss[s[i]]++;
    for(auto i : mp){
        if(ss[i.first] < i.second)
            return false;
    }
    return true;
}


string Solution::minWindow(string A, string B) {
    int i, j, k;
    unordered_map<char, int> subl;
    for(i = 0; i < B.length(); i++)
        subl[B[i]]++;
    int l = A.length();
    for(i = B.length(); i <= l; i++){
        for(j = 0; j < l - B.length() + 1; j++){
            string s = A.substr(j, i);
            if(check(subl, s))
                return s;
        }   
    }
    return "";
}
