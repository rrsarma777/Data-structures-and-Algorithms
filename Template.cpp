#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
void fastIO() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
template<class... T> void read(T&... args) { ((cin >> args), ...); }
template<class T> void _deb(T t) { cerr << t; }
template<class... T> void deb(T... args) { ((cerr << args << ' '), ...); cerr << '\n'; }
template<class T> void _deb(vector<T>& ar) {  cerr << "[ "; for(T t : ar) { _deb(t); cerr << " "; } cerr << "]\n"; }
template<class T> void _deb(set<T>& s) {  cerr << "[ "; for(T t : s) { _deb(t); cerr << " "; } cerr << "]\n"; }
template<class T> void _deb(unordered_set<T>& us) {  cerr << "[ "; for(T t : us) { _deb(t); cerr << " "; } cerr << "]\n"; }
template<class K, class V> void _deb(map<K, V>& m) {  cerr << "[ "; for(auto x : m) { cerr << "{"; _deb(x.first); cerr << " : "; _deb(x.second); cerr << "} "; } cerr << "]\n"; }
template<class K, class V> void _deb(unordered_map<K, V>& m) {  cerr << "[ "; for(auto x : m) { cerr << "{"; _deb(x.first); cerr << " : "; _deb(x.second); cerr << "} "; } cerr << "]\n"; }
const int PRIMES_1E5 = 1299720;
const int mxn = 1e7 + 1;

void solve() {
	int n;
	cin >> n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	freopen("err", "w", stderr);
#else
#define cerr if(false) cerr
#endif
	fastIO();
	int T = 1;
	bool hasTestCases = 1;
	if (hasTestCases) cin >> T;
	while (T--) solve();
}
