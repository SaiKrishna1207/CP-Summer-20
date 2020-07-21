long long convertInt(string a){
    long long x = 0;
    int l = a.length(), i;
    for(i = 0;i < l; i++){
        int k = a[i] - '0';
        x = (x * 10) + k; 
    }
    return x;
} 

string convertString(long long x){
    int i, j;
    string ans = "";
    while(x){
        j = x%10;
        char c = '0' + j;
        ans = c + ans;
        x /= 10;
    }
    return ans;
}

string Solution::multiple(int A) {
    int i, j, k;
    if(A == 0)
        return "0";
    if(A == 1)
        return "1";
    queue<string> q;
    q.push("1");
    while(!q.empty()){
        string s = q.front();
        q.pop();
        long long x = convertInt(s);
        if(x%A == 0)
            return s;
        x *= 10;
        q.push(convertString(x));
        q.push(convertString(x + 1));
    }
    return "";
}
