#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long machinesMade(long long time, vector<long> & machines)
{
    int i, j;
    long long count = 0;
    for(i = 0; i < machines.size(); i++)
        count += (time / machines[i]);
    return count;
}

long long minTime(vector<long> machines, long goal) {
    sort(machines.begin(), machines.end());
    int i, j, k, n = machines.size();
    long long maxTime = (machines[n - 1] * goal) / n;
    long long minTime = (machines[0] * goal) / n;
    long long l = minTime, h = maxTime, ans;
    while(l <= h)
    {
        long long m = l + ((h - l) / 2);
        long long machineCount = machinesMade(m, machines);
        if(machineCount == goal)
        {
            while(machinesMade(m,machines) == goal)
                m--;
            ans = m + 1;
            break;
        }
        else if(machineCount > goal)
        {
            if(machinesMade(m - 1, machines) < goal)
            {
                ans = m;
                break;
            }
            else
                h = m - 1;
        }
        else if(machineCount < goal)
            l = m + 1;
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nGoal_temp;
    getline(cin, nGoal_temp);

    vector<string> nGoal = split_string(nGoal_temp);

    int n = stoi(nGoal[0]);

    long goal = stol(nGoal[1]);

    string machines_temp_temp;
    getline(cin, machines_temp_temp);

    vector<string> machines_temp = split_string(machines_temp_temp);

    vector<long> machines(n);

    for (int i = 0; i < n; i++) {
        long machines_item = stol(machines_temp[i]);

        machines[i] = machines_item;
    }

    long long ans = minTime(machines, goal);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
