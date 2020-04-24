#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n) {
    int ways[n];
    int i, j, k;
    ways[0] = 1;
    ways[1] = 2;
    ways[2] = 4;
    for(i = 3;i < n; i++)
        ways[i] = ways[i-1] + ways[i-2] + ways[i-3];
    return ways[n-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
