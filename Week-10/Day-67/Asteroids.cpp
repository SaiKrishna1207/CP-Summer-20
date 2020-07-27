class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i, j, k;
        if(!asteroids.size())
            return {};
        stack<int> st;
        vector<int> ans;
        for(i = 0; i < asteroids.size(); i++){
            if(asteroids[i] < 0){
                if(st.empty())
                    ans.push_back(asteroids[i]);
                else{
                    k = st.top();
                    st.pop();
                    if(k > abs(asteroids[i]))
                        st.push(k);
                    else if(k < abs(asteroids[i]))
                        i--;
                }
            }
            else
                st.push(asteroids[i]);
        }
        int l = ans.size();
        while(!st.empty()){
            k = st.top();
            st.pop();
            ans.push_back(k);
        }
        reverse(ans.begin() + l, ans.end());
        return ans;
    }
};