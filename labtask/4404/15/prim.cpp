#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pl;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define f first
#define s second


vector<pl> adj[200000];
int n;
ll MAX = 100000000000L;
ll prim(){
	ll weight = 0;
	vector<ll> min(n, MAX);
	min[0] = 0;
	set<pl> q;
	q.insert({0, 0});
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (q.empty()) {
			return -1;
		}
		int v = q.begin() -> s;
		visited[v] = true;
		weight += q.begin()-> f;
		q.erase(q.begin());

		for (pl e : adj[v]) {
			if(!visited[e.s] && e.f < min[e.s]) {
				q.erase({min[e.s], e.s});
				min[e.s] = e.f;
				q.insert({e.f, e.s});
			}
		}
	}
	return weight;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m; cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b; ll c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a].pb(mp(c, b));
		adj[b].pb(mp(c, a));
	}
	ll ans = prim();
	if(ans == -1){
		cout << "IMPOSSIBLE";
	}
	else{
		cout << ans;
	}
	return 0;
}
