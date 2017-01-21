#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii edges[444444];
int fa[222222];
int connect_s[222222];
int connect_t[222222];
void update(int &x, int v) {
	if (v != -1) x = v;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int n, m;
bool check_st(int s, int t, int ds, int dt, vector<int> &ans) {
	set<int> onlyS;
	set<int> onlyT;
	set<int> both;
	for (int i = 1; i <= n; ++i) {
		if (i == s || i == t) continue;
		if (i != get(i)) continue;
		if (connect_s[i] == -1 && connect_t[i] == -1) {
			return false;
		} else
		if (connect_s[i] != -1 && connect_t[i] != -1) {
			both.insert(i);
		} else
		if (connect_s[i] != -1) {
			onlyS.insert(i);
		} else
		if (connect_t[i] != -1) {
			onlyT.insert(i);
		}
	}
	while (onlyS.size()) {
		ans.push_back(connect_s[*onlyS.begin()]);
		onlyS.erase(onlyS.begin());
		--ds;
	}
	while (onlyT.size()) {
		ans.push_back(connect_t[*onlyT.begin()]);
		onlyT.erase(onlyT.begin());
		--dt;
	}
	if (both.size() >= 1) {
		int x = *both.begin();
		ans.push_back(connect_s[x]);
		ans.push_back(connect_t[x]);
		both.erase(x);
	} else {
		if (connect_s[t] == -1) return false;
		ans.push_back(connect_s[t]);
	}
	--ds;
	--dt;
	if (ds < 0 || dt < 0) return false;
	while (both.size()) {
		int x = *both.begin();
		if (ds) {
			--ds;
			ans.push_back(connect_s[x]);
		} else 
		if (dt) {
			--dt;
			ans.push_back(connect_t[x]);
		} else {
			return false;
		}
		both.erase(x);
	}
	return true;
}

int main(void) {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) fa[i] = i;

	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		edges[i] = pii(u, v);
	}
	int s, t, ds, dt;
	vector<int> ans;
	scanf("%d %d %d %d", &s, &t, &ds, &dt);
	if (s > t) {
		swap(s, t);
		swap(ds, dt);
	}
	memset(connect_t, -1, sizeof connect_t);
	memset(connect_s, -1, sizeof connect_s);
	for (int i = 0; i < m; ++i) {
		int u = edges[i].first;
		int v = edges[i].second;
		if (u == s) {
			connect_s[v] = i;
		}
		if (u == t) {
			connect_t[v] = i;
		}
		if (v == s) {
			connect_s[u] = i;
		}
		if (v == t) {
			connect_t[u] = i;
		}
		if (u == s || v == s) continue;
		if (u == t || v == t) continue;
		if (get(u) != get(v)) {
			fa[get(u)] = get(v);
			ans.push_back(i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		update(connect_s[get(i)], connect_s[i]);
		update(connect_t[get(i)], connect_t[i]);
	}

	if (check_st(s, t, ds, dt, ans)) {
		puts("Yes");
		for (auto x : ans) {
			printf("%d %d\n", edges[x].first, edges[x].second);
		}
		return 0;
	}

	puts("No");
	return 0;
}