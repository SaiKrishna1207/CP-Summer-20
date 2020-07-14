bool isPali(string a){
    if(!a.length())
        return true;
    int i, l = a.length();
    for(i = 0; i < l / 2; i++){
        if(a[i] != a[l - i - 1])
            return false;
    }
    return true;
}


void recurse(vector<vector<string>>& ans, vector<string>& t, string A, int cur){
    if(cur >= A.length()){
        ans.push_back(t);
        return;
    }

    int i;
    for(i = 1;i <= A.length() - cur; i++){
        string s = A.substr(cur, i);
        if(isPali(s)){
            t.push_back(s);
            recurse(ans, t, A, cur + i);
            t.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string> t;
    int i, j, k;
    int l = A.length();
    if(!l)
        return {};
    recurse(ans, t, A, 0);
    return ans;
}
bool isPali(string a){
    if(!a.length())
        return true;
    int i, l = a.length();
    for(i = 0; i < l / 2; i++){
        if(a[i] != a[l - i - 1])
            return false;
    }
    return true;
}


void recurse(vector<vector<string>>& ans, vector<string>& t, string A, int cur){
    if(cur >= A.length()){
        ans.push_back(t);
        return;
    }

    int i;
    for(i = 1;i <= A.length() - cur; i++){
        string s = A.substr(cur, i);
        if(isPali(s)){
            t.push_back(s);
            recurse(ans, t, A, cur + i);
            t.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string> t;
    int i, j, k;
    int l = A.length();
    if(!l)
        return {};
    recurse(ans, t, A, 0);
    return ans;
}
