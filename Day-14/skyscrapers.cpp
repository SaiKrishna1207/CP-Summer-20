#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int i, n, k, sum1 = 0, sum2 = 0, c2 = 0;
    vector<int> max;
    vector<int> front, back;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> k;
        max.push_back(k);
    }
    max.push_back(0);
    front.push_back(max[0]);
    sum1 += max[0];
    for(i = 1;i < n; i++)
    {
        if(max[i] >= max[i-1])
        {
            sum1 += max[i];
            front.push_back(max[i]);
        }
        else if(max[i] < max[i-1])
        {
            if(max[i+1] <= max[i])
            {
                sum1 += max[i];
                front.push_back(max[i]);
            }
            else
            {
                sum1 += (2 * max[i]);
                front.push_back(max[i]);
                front.push_back(max[i]);
                i++;
            }
        }
    }
    //10 6 8
    back.push_back(max[n - 1]);
    c2++;
    sum2 += max[n - 1];
    for(i = n - 2;i > 0; i--)
    {
        if(max[i] >= max[i + 1])
        {
            c2++;
            sum2 += max[i];
            back.push_back(max[i]);
        }
        else if(max[i] < max[i + 1])
        {
            if(max[i - 1] <= max[i])
            {
                c2++;
                sum2 += max[i];
                back.push_back(max[i]);
            }
            else
            {
                c2 += 2;
                sum2 += (2 * max[i]);
                back.push_back(max[i]);
                back.push_back(max[i]);
                i--;
            }
        }
    }
    if(c2 == n - 1)
    {
        if(max[1] >= max[2])
        {
            sum2 += max[0];
            back.push_back(max[0]);
        }
        else
        {
            if(max[0] > max[1])
            {
                sum2 += max[1];
                back.push_back(max[1]);
            }
            else
            {
                sum2 += max[0]; 
                back.push_back(max[0]);
            }
        }
    }
    // cout << sum1 << " " << sum2 << endl;
    int flag;
    if(sum1 >= sum2)
        flag = 0;
    else
        flag = 1;
    if(flag == 0)
    {
        for(i = 0;i < n; i++)
            cout << front[i] << " ";
        cout << endl << sum1 << endl;
    }
    else
    {
        for(i = n - 1;i >= 0; i--)
            cout << back[i] << " ";
        cout << endl << sum2 << endl;
    }
    return 0;
}
