#include<bits/stdc++.h>

using namespace std;

int findMax(vector<int> seq)
{
    int n = seq.size();
    int i, j;
    vector<int> maxes;
    maxes.push_back(1);
    for(i = 1;i < n; i++)
    {   
        if(seq[i] > seq[i - 1])
            maxes.push_back(maxes[i - 1] + 1);
        else
            maxes.push_back(1);
    }
    int max = maxes[0];
    for(i = 1;i < n; i++)
    {
        if(maxes[i] > max)
            max = maxes[i];
    }
    return max;
}

int main()
{
    int n, i, j, k, max;
    vector<int> sequence;
    vector<int>::iterator it;
    cin >> n;
    for(i = 0;i < n; i++)
    {
        cin >> k;
        sequence.push_back(k);
    }
    max = findMax(sequence);
    for(i = 0;i < n; i++)
    {
        j = sequence[i];
        it = sequence.begin() + i;
        sequence.erase(it);
        int m = findMax(sequence);
        if(m > max)
            max = m;
        sequence.insert(it, j);
    }
    cout << max << endl;



    return 0;
}