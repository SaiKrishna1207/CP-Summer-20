#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q, i, n, h, k, count;
    cin >> q;
    vector <int> answers;
    unordered_map<int, int> platforms;
    while(q--)
    {  
        count = 0;
        cin >> h >> n;
        for(i = n;i >= 1; i--)
        {
            cin >> k;
            platforms[i] = k;
        }
        k = n;
        while(k > 1)
        {
            if(platforms[k] - platforms[k-1] == 1)
            {
                if(platforms[k-1] - platforms[k-2] == 1)
                    k = k - 2;
                else
                {
                    count++;
                    platforms[k-1]--;
                    k--;
                }
            }
            else 
            {
                platforms[k] = platforms[k-1] + 1;
            }
        }
        answers.push_back(count);
        platforms.erase(platforms.begin(), platforms.end());
    }

    for(i = 0;i < answers.size(); i++)
        cout << answers[i] << endl;
    return 0;
}