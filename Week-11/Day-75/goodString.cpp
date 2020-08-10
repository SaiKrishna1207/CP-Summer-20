#include<bits/stdc++.h>

using namespace std;

int main(){
    int i, j, k;    
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        int l = s.length();
        if(l < 3){
            cout << 0 << endl;
            continue;
        }
        int ans = l - 2;
        for(i = 0;i < 10; i++){
            for(j = 0; j < 10; j++){
                int c = 0;
                for(k = 0; k < l; k++){
                    if(c%2 == 0 && s[k] == '0' + i) 
                        c++;
					else if(c%2 == 1 && s[k] == '0' + j)
                        c++;
                }
				if(i != j && c%2 == 1) 
                    c--;
				ans = min(ans,l - c);
            }
        }
        cout << ans << endl;
    }
    return 0;
}