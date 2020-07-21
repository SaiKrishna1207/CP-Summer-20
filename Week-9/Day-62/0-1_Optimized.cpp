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

string Solution::multiple(int N) {
    int i, j, k;
    if(N == 1) 
        return "1";
    if(N == 0)
        return "0";
    vector<int> parent(N, -1);
    vector<int> s(N, -1);
    queue<int> q;
    q.push(1);
    while(q.front() != 0){
        int curr = q.front();
        q.pop();
        for(i = 0;i < 2; i++){
            int next = ((curr * 10) + i)%N;
            if(parent[next] == -1){
                parent[next] = curr;
                s[next] = i;
                q.push(next);
            }
        }
    }
    //build reversed string
    string ans = "";
    for(i = 0; i != 1; i = parent[i]){
        char c = s[i] + '0'; 
        ans = c + ans;
    }
    ans = "1" + ans;
    //return the reverse if it
    return ans;
}
