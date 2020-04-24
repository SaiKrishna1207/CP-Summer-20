#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


//Logic : Next state[i] = currentstate[i] XOR currentstate[i-1] XOR currentstate[i+1] ---- 1
//        We have all the nextstates. We need to find the current state
//From above equation, we see that currentstate[i+1] = Nextstate[i] XOR currentstate[i] XOR currentstate[i-1]---- 2
//We have all the nextstates. for every currentstate..you need the previous 2 currentstates.
//So we take the 4 possible combinations of the first 2 states - 00 01 10 and 11 and find the corresponding currentstate using equation 2
//We then check the currentstate using equation 1 for the corner cases.
//Since there are only 4 cases, its simple.

bool check_prev(int* arr, int* ans, int n)
{
    int i,j;
    for(i = 2;i < n; i++)
        ans[i] = ans[i-1]^ans[i-2]^arr[i-1]; 
    if (ans[n-2]^ans[n-1]^ans[0]^arr[n-1])      //Verifying first element
        return false;
    if (ans[n-1]^ans[0]^ans[1]^arr[0])          //Verifying last element
        return false;
    
    return true;
}

int main()
{
    int i, j, t, n, count;
    string str;
    cin>>t;
    vector<string> cases;
    for(i = 0;i < t; i++)
    {
        cin >> str;
        cases.push_back(str);
    }
    i = 0;
    while(t--)
    {
        str = cases[i];
        n = str.length();
        int arr[n], ans[n];
        int a,b;
        count = 0;
        for(j = 0;j < n; j++)
            arr[j] = str[j] - 48;
        for(j = 1;j <= 4; j++)
        {
            switch(j)
            {
                case 1 : ans[0] = 0;
                         ans[1] = 0;
                         break;
                case 2 : ans[0] = 0;
                         ans[1] = 1;
                         break;
                case 3 : ans[0] = 1;
                         ans[1] = 0;
                         break;
                case 4 : ans[0] = 1;
                         ans[1] = 1;
                         break;
            }             
            if(check_prev(arr, ans, n))
            {
                count++;
                a = ans[0];
                b = ans[1];
            }
        }
        if(count == 0)
            cout << "No solution" << endl;
        else if(count>1)
            cout << "Multiple solutions" << endl;
        else if(count == 1)
        {
            ans[0] = a;
            ans[1] = b;
            check_prev(arr, ans, n);
            for(j = 0;j < n; j++)
                cout << ans[j];
            cout<<endl;
        }
        i++;
    }
    return 0;
}