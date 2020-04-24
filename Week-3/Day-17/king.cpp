#include<bits/stdc++.h>

using namespace std;

float dist(int x1, int y1, int x2, int y2)
{
    float distance = sqrt(((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)));
    return distance;
}

int main()
{
    vector<string> moves;
    string move;
    string start, dest;
    int i, move_count = 0;
    cin >> start >> dest;
    int x1 = start[0] - 97;
    int y1 = start[1] - 48;
    int x2 = dest[0] - 97;
    int y2 = dest[1] - 48;
    y2--;
    y1--;
    if(x1 == x2 && y1 == y2)
    {
        cout << 0;
        return 0;
    }
    while(1)
    {
        int addx = 0, addy = 0;
        float min = dist(x1, y1, x2, y2);
        if((dist(x1, y1 + 1, x2, y2) < min) && (x1 < 8 && y1+1 < 8 && x1 >= 0 && y1+1 >= 0))
        {
            min = dist(x1, y1 + 1, x2, y2);
            move = "U";
            addy = 1;
            addx = 0;
        }
        if((dist(x1 + 1, y1 + 1, x2, y2) < min) && (x1+1 < 8 && y1+1 < 8 && x1+1 >= 0 && y1+1 >= 0))
        {
            min = dist(x1 + 1, y1 + 1, x2, y2);
            move = "RU";
            addx = 1;
            addy = 1;
        }
        if((dist(x1 + 1, y1, x2, y2) < min) && (x1+1 < 8 && y1 < 8 && x1+1 >= 0 && y1 >= 0))
        {
            min = dist(x1 + 1, y1, x2, y2);
            move = "R";
            addx = 1;
            addy = 0;
        }      
        if((dist(x1 + 1, y1 - 1, x2, y2) < min) && (x1+1 < 8 && y1-1 < 8 && x1+1 >= 0 && y1-1 >= 0))
        {
            min = dist(x1 + 1, y1 - 1, x2, y2);
            move = "RD";
            addx = 1;
            addy = -1;
        }
        if((dist(x1, y1 - 1, x2, y2) < min) && (x1 < 8 && y1-1 < 8 && x1 >= 0 && y1-1 >= 0))
        {
            min = dist(x1, y1 - 1, x2, y2);
            move = "D";
            addy = -1;
            addx = 0;
        }
        if((dist(x1 - 1, y1 - 1, x2, y2) < min) && (x1-1 < 8 && y1-1 < 8 && x1-1 >= 0 && y1-1 >= 0))
        {
            min = dist(x1 - 1, y1 - 1, x2, y2);
            move = "LD";
            addx = -1;
            addy = -1;
        }
        if((dist(x1 - 1, y1, x2, y2) < min) && (x1-1 < 8 && y1 < 8 && x1-1 >= 0 && y1 >= 0))
        {
            min = dist(x1 - 1, y1, x2, y2);
            move = "L";
            addx = -1;
            addy = 0;
        }
        if((dist(x1 - 1, y1 + 1, x2, y2) < min) && (x1-1 < 8 && y1+1 < 8 && x1-1 >= 0 && y1+1 >= 0))
        {
            min = dist(x1 - 1, y1 + 1, x2, y2);
            move = "LU";
            addx = -1;
            addy = 1;
        }
        x1 += addx;
        y1 += addy;
        // cout << x1 << " " << y1 << endl;
        move_count++;
        // cout << x1 << " " << y1 << endl;
        moves.push_back(move);
        if(x1 == x2 && y1 == y2)
            break;
    }
    cout << move_count << endl;
    for(i = 0;i < moves.size(); i++)
        cout << moves[i] << endl;   
}