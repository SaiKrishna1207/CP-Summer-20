class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int i, j;
        char ch = 'd';
        string ans = "";
        while(true)
        {
            if(a >= b && a >= c && ch != 'a' && a){
                ch = 'a';
                ans += "a";
                a--;
                if(a){
                    ans += "a";
                    a--;
                }
            }
            else if(b >= a && b >= c && ch != 'b' && b){
                ch = 'b';
                ans += "b";
                b--;
                if(b){
                    ans += "b";
                    b--;
                }
            }
            else if(c >= b && c >= a && ch != 'c' && c){
                ch = 'c';
                ans += "c";
                c--;
                if(c){
                    ans += "c";
                    c--;
                }
            }
            else if(ch != 'a' && a){
                ch = 'a';
                ans += "a";
                a--;
            }
            else if(ch != 'b' && b){
                ch = 'b';
                ans += "b";
                b--;
            }
            else if(ch != 'c' && c){
                ch = 'c';
                ans += "c";
                c--;
            }
            else
                break;
        }
        return ans;
    }
};