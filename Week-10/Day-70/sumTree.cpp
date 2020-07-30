class Solution {
	int n;
	vector<vector<int>> mp;
	vector<int> sz, val, ans;

	void dfs1(int cur, int par) {

		for (auto i : mp[cur]) {
			if (i != par) {
				dfs1(i, cur);
				sz[cur] += sz[i];
				val[cur] += val[i] + sz[i];
			}
		}
		sz[cur]++;
	}

	void dfs2(int cur, int par, int dpVal) {
		ans[cur] = val[cur] + dpVal + (n - sz[cur]);

		for (auto i : mp[cur]) {
			if (i != par)
				dfs2(i, cur, ans[cur] - val[i] - sz[i]);
		}
	}
    
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		n = N;
		mp.resize(n), sz.resize(n), val.resize(n), ans.resize(n);
		for (vector<int> &v : edges) {
			mp[v[0]].push_back(v[1]);
			mp[v[1]].push_back(v[0]);
		}
		dfs1(0, 0);
		dfs2(0, 0, 0);
		return ans;
	}
};