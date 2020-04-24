#include<bits/stdc++.h>

using namespace std;

bool isPali(char* time)
{
    if(time[0] == time[4] && time[3] == time[1])
        return true;
    return false;
}

int main()
{
    char time[10] = {' '};
    cin >> time;
    while(1)
    {
        if(time[4] != '9')
            time[4]++;
        else
        {
            time[4] = '0';
            if(time[3] != '5')
                time[3]++;
            else
            {
                time[3] = '0';
                if(time[1] != '9' && time[0] != '2')
                    time[1]++;
                else if(time[1] == '9' && time[0] != '2')
                {
                    time[1] = 0;
                    time[0]++;   
                }
                else if(time[1] != '3' && time[0] == '2')
                    time[1]++;
                else 
                {
                    time[1] = '0';
                    time[0] = '0';
                }
            }
        }
        if(isPali(time))
            break;
    }
    cout << time << endl;
    return 0;
}