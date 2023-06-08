#include <bits/stdc++.h>

using namespace std;

// Type definitions
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int> 
#define vl vector<ll>
#define vld vector<ld> 
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vpld vector<pair<ld, ld>>  

// Macros
#define rep(i,a,b) for(int i=a; i<b; i++)
#define itr(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define all(v) v.begin(), v.end()
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

// Optimization macros
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// This optimizes the input/output operations by disabling synchronization with C input/output streams
// and tying cin and cout to NULL streams for faster I/O.
#define pr double(clock()/CLOCKS_PER_SEC) 
// This returns the current time in seconds, which can be used to measure the execution time of a program.
#define debug(x) cerr << #x << " is " << x << endl;
// This prints a variable name and its value to the standard error stream for debugging purposes.

// Constants
const ll INF = 2e18;
const int mod = 1e9 + 7;
const int MAXN = 2e5 + 5;

// Function prototypes 
void solve();

// Disjoint set union 
// (keep track of connected components)
struct dsu{
    vi par, size;
    void init(int n){
        par.resize(n);
        size.resize(n,1);
        rep(i,0,n) par[i] = i;
    }
    
    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    
    void unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(size[px] > size[py]) swap(px,py);
        par[px] = py;
        size[py] += size[px];
    }
};

int main() 
{
    //fast; // Uncomment this line if you want to optimize input/output operations.
    int t = 1; 
    cin >> t;
    while(t--) 
        solve();
    return 0;
}

const int MAXP = 101;

int a[MAXP][MAXP];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
        }
    }
    cout << a[1][1] << endl;
}
