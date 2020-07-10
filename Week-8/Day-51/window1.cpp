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
    i = 0, j = B.length() - 1;
    string ans = "";
    while(i < A.length() && j < A.length() && j - i + 1 >= B.length()){
        string s = A.substr(i, j - i + 1);
        if(check(subl, s)){
            if(s.length() < ans.length() || ans == "")
                ans = s;
            i++;
        }
        else
            j++;
    }
    return ans;
}
