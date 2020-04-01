#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q, i, n, h, k, count;
    cin >> q;
    vector <int> answers;
    unordered_map<int, bool> platforms;
    while(q--)
    {  
        count = 0;
        cin >> h >> n;
        for(i = 0;i < n; i++)
        {
            cin >> k;
            platforms[k] = 1;
        }
        i = h;
        while(i > 2)
        {
            if(platforms.find(i-1) != platforms.end() && platforms.find(i-2) != platforms.end())
            {
                // platforms[i] = 0;
                // platforms[i-1] = 0;
                i -= 2;
            }
            else if(platforms.find(i-1) == platforms.end())
            {
                // platforms[i] = 0;
                // platforms[i-1] = 1;
                i--;
            }
            else if(platforms.find(i-1) != platforms.end() && platforms.find(i-2) == platforms.end()) // using magic crystals
            {
                count++;
                // platforms[i-2] = 1;
                // platforms[i-1] = 0;
                // platforms[i] = 0;
                i -= 2;
            }
        }
        answers.push_back(count);
        platforms.erase(platforms.begin(), platforms.end());
    }

    for(i = 0;i < answers.size(); i++)
        cout << answers[i] << endl;
    return 0;
}