int Solution::repeatedNumber(const vector<int> &A) {
    int l = A.size();
    int i;
    unordered_map <int, int> m;
    for(i = 0;i < l;i++)
        m[A[i]]++;
    for(auto i: m)
    {
        if(i.second > l/3)
        {
            return i.first;
        }
    }
    return -1;
}
