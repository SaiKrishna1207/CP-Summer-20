#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void solve(vector<string> cases)
{
    //abaabbccbccdd
    int i,j,k, count  = 0;
    string str, res, s = "";
    char a;
    int l = cases.size();
    vector<string> answers;
    int alphabet_in[26];

    for(i = 0;i < l; i++)
    {
        s = "";
        str = cases[i];
        for(j = 0;j < 26;j++) 
        {
            alphabet_in[j] = 0;
        }
        for(j = 0;j < str.length();j++)
        {
            if(str[j] >= 97 && str[j] <= 122){
                k = str[j] - 97;
                alphabet_in[k] = -1;
            }
        }
        //cbddbb 0 1 1 -1...
        for(j = 0;j < str.length(); j++)
        {
            count = 0;
            a = str[j];
            k = j;
            if(alphabet_in[a-97] == -1){
                while(str[k] == a){
                    count++;
                    k++;
                }
            }
            else
                continue;
            if(count%2 == 1 && alphabet_in[a-97] == -1)
            {
                alphabet_in[a-97] = 1;
                j = k-1;
            }
            j = k-1;
        }
        for(j = 0;j < 26; j++)
        {
            if(alphabet_in[j] == 1)
            {
                a = 97 + j;
                s = s + a;
            }
        }
        answers.push_back(s);
    }

    for(i = 0;i < l;i++)
    {
        res = answers[i];
        cout<<res<<endl;
    }

}

int main() 
{
    int t, i;
    string s;
    //cout << "Enter the number of testcases." << endl;
    cin >> t;
    vector<string> cases;
   // cout << "Enter the strings" << endl;
    for(i = 0;i < t;i++){
        cin >> s;
        cases.push_back(s);
    }    
    solve(cases);
    return 0;
}