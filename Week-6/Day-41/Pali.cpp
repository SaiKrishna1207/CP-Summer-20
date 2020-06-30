bool isPalindrome(string a){
    int i, l = a.length();
    for(i = 0;i < l / 2; i++){
        if(a[i] != a[l - i - 1])
            return false;
    }
    return true;
}

string Solution::longestPalindrome(string A) {
    int i, j;
    if(isPalindrome(A))
        return A;
    int l = A.length();
    for(i = l - 1; i >= 1; i--){
        string sub;
        for(j = 0;j <= l - i; j++){
            sub = A.substr(j, i);
            if(isPalindrome(sub))
                return sub;
        }
    }
    string k = "";
    k += A[0];
    return k;
}
