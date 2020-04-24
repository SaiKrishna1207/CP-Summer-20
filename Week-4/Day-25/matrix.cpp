#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[2] > v2[2]; 
} 

bool FindMachine(int x, unordered_map<int, vector<int>> & m, bool* machPres)
{  
    int i;
    if(!m[x].size())
        return false;
    for(i = 0;i < m[x].size(); i++)
    {
        if(machPres[m[x][i]])
            return true;
        if(FindMachine(m[x][i], m, machPres))
            return true;
    }
    return false; 
}


int minTime(vector<vector<int>> roads, vector<int> machines) {
    sort(roads.begin(), roads.end(), sortcol);
    int n = roads.size() + 1;
    int k = machines.size();
    int ans = 0, i, j;
    unordered_map<int, vector<int>> m;
    bool machPres[n] = {false};
    // for(i = 0; i < n - 1; i++)
    //     cout << roads[i][2] << endl;
    for(i = 0;i < k; i++)
        machPres[machines[i]] = true;
    for(i = 0;i < n - 1; i++)
    {
        if(!machPres[roads[i][0]] && !machPres[roads[i][1]])
        {
            m[roads[i][0]].push_back(roads[i][1]);
            m[roads[i][1]].push_back(roads[i][0]);
        }
        else if(machPres[roads[i][0]] && machPres[roads[i][1]])
            ans += roads[i][2];
        
        else if(machPres[roads[i][0]] && !machPres[roads[i][1]])
        {
            if(FindMachine(roads[i][1], m, machPres))
                ans += roads[i][2];
            else
            {
                m[roads[i][0]].push_back(roads[i][1]);
                m[roads[i][1]].push_back(roads[i][0]);
            }
        }
        
        else if(!machPres[roads[i][0]] && machPres[roads[i][1]])
        {            
            if(FindMachine(roads[i][0], m, machPres))
                ans += roads[i][2];
            else
            {
                m[roads[i][0]].push_back(roads[i][1]);
                m[roads[i][1]].push_back(roads[i][0]);
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines);

    fout << result << "\n";

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
