#include <bits/stdc++.h>

using namespace std;


//Since array is repeated n times, each element is repeated n times. This means that whatever happens since they are the same numbers occuring again and again,
//the max size of a subsequence would equal to the number of distinct elements in the array.

int main() 
{
    int n, t, i, j;
    vector<int>::iterator it; 
    vector<int> answers;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> arr;
        unordered_map <int, int> m;
        for(i = 0;i < n; i++)
        {
            cin >> j;
            arr.push_back(j);
            m[j]++;
        }
        answers.push_back(m.size());
        arr.clear();
    }
    for(i = 0;i < answers.size(); i++)
        cout << answers[i] << endl;
    return 0;
}