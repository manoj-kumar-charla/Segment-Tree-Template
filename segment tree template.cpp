
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
using namespace std;

#define DEBUG(x...) { cout << "(" << #x << ")" << " = ("; Print(x); }
template <typename T1> void Print(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void Print(T1 t1, T2... t2) { cout << t1 << ","; Print(t2...); }

#define int long long
#define ll long long
#define ld long double
#define ull unsigned long long
#define ip(x) int x; cin >> x
#define ipt(x, t) t x; cin >> x
#define opnl(x) cout << x << "\n"
#define nl cout << endl
#define op(x) cout << x << " "
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
 
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vd vector<ld>
#define vpi vector<pi>
#define vpl vector<pl>
 
#define vvi vector<vector<ll>>
#define vvvi vector<vector<vector<ll>>>
 
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define po pop_back
#define F first
#define S second
#define ins insert
 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
#define lb(vn, x) lower_bound(vn.begin(), vn.end(), x) - vn.begin()
#define ub(vn, x) upper_bound(vn.begin(), vn.end(), x) - vn.begin()
 
#define endl '\n'
 
#define speed_ ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
 
#define sp(x) fixed << setprecision(x)
#define uni(arr) arr.erase(unique(arr.begin(), arr.end()), arr.end());
 
#define to_up(x) transform(x.begin(), x.end(), x.begin(), ::toupper)
#define to_low(x) transform(x.begin(), x.end(), x.begin(), ::tolower)
 
#define input(v, n)            \
    for (ll i = 0; i < n; i++) \
        cin >> v[i];
#define Sort(v) sort(v.begin(), v.end())
 
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = a; i >= b; i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)
 
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
 
const int M = 1000000007;
const int MM = 998244353;
// const ld Pi= acos(-1);
const int N = 1e6 + 5;
#define INF 1e18

#define ip(x) int x; cin >> x
#define ipt(x, t) t x; cin >> x
#define opnl(x) cout << x << "\n"
#define nl cout << endl
#define op(x) cout << x << " "

void debug(vi &v)
{
	for(int i=0; i<sz(v); i++)
	{
		op(v[i]);
	}
	nl;
}


class segTree {
public:
    vector<int> sgt;
    int n;
    segTree(int p) {
        n = 1;
        while (n < p) {
            n *= 2;
        }
        sgt = vector<int>(2*n, 0);
    }
    void build(vector<int> &a){
    	build(a, 0, 0, n);
    }
    void build(vector<int> &a, int x, int lx, int rx){
    	if(rx - lx == 1){
    		if(lx < sz(a)){
    			sgt[x] |= (1LL << a[lx]);
    		}
    		return;
    	}
    	
    	int mid = (lx + rx) / 2;
    	build(a, 2 * x + 1, lx, mid);
    	build(a, 2 * x + 2, mid, rx);
    	int left = sgt[2 * x + 1], right = sgt[2 * x + 2];
    	sgt[x] = left | right;
    }
    void set(int i, int val){
    	set(i, val, 0, 0, n);
    }
    void set(int i, int val, int x, int lx, int rx){
    	
    	if(rx - lx == 1){
    		sgt[x] = (1LL << val);
    		return;
    	}
    	
    	int mid = (lx + rx) / 2;
    	if(i < mid){
    		set(i, val, 2 * x + 1, lx, mid);
    	}else{
    		set(i, val, 2 * x + 2, mid, rx);
    	}
    	int left = sgt[2 * x + 1], right = sgt[2 * x + 2];
    	sgt[x] = left | right;
    }
    int count(int l, int r){
    	return count(l, r, 0, 0, n);
    }
    int count(int l, int r, int x, int lx, int rx){
    	if(lx >= r || rx <= l) return 0;
    	if(lx >= l && rx <= r) return sgt[x];
    	
    	int mid = (lx + rx) / 2;
    	int left = count(l, r, 2 * x + 1, lx, mid);
    	int right = count(l, r, 2 * x + 2, mid, rx);
    	return (left | right);
    }
};

int countBits(int mask){
	int cnt = 0;
	while(mask > 0){
		if(mask % 2) cnt++;
		mask /= 2;
	}
	return cnt;
}


void solve() {
	ip(n);
	ip(q);
	vi a(n);
	input(a, n);
	
	segTree t(n);
	t.build(a);
	
	while(q--){
		ip(type);
		if(type == 2){
			ip(i);
			ip(val);
			--i;
			t.set(i, val);
		}else{
			ip(l);
			ip(r);
			--l;
			int mask = t.count(l, r);
			int ans = countBits(mask);
			opnl(ans);
		}
	}
}

bool multiple = 1;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // if (multiple) cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
