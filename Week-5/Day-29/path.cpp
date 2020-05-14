class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string ans="";
        int i=0;
        while(i < path.size())
        {
            char ch = path[i];
            string str = "";
            int j = 0;
            if(ch == '/'){
                for(j = i + 1; j < path.size(); j++)
                {
                    ch = path[j];
                    if(ch == '/')
                        break;
                    str += ch;
                }
            }
            if(str == "..") 
            {
                if(!s.empty())
                    s.pop();
            }
            else if(str == "." || str == "")
                i = j;
            else
                s.push(str);
            i = j;
        }
        while(!s.empty())
        {
            string temp = s.top();
            s.pop();
            ans = "/" + temp + ans;
        }
        if(ans == "")
            ans = "/";
        return ans;
    }
}; 