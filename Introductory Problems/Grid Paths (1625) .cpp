#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using u128 = __uint128_t;
 
#define int long long
#define idxSet tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define atIdx find_by_order
#define idxOf order_of_key
#define MOD 1000000007
#define MAX 200005
#define endl '\n'
 
#define v(type) vector<type>
#define p(type1, type2) pair<type1 , type2>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int dp[MAX];
 
int ans = 0;
 
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
 
bool grid[7][7];
 
bool isPossible(int xi, int yi) {
    return xi >= 0 && xi <= 6 && yi >= 0 && yi <= 6 && !grid[xi][yi];
}
 
void countWays(int ith, string &s, int xi, int yi, char from = '\0') {
    if (xi == 6 && yi == 0) {
        if (ith == 48) ans++;
        return;
    }
    if(from == 'U' && (xi == 0 || grid[xi - 1][yi]) && yi > 0 && yi < 6 && !grid[xi][yi-1] && !grid[xi][yi+1]) return;
    if(from == 'R' && (yi == 6 || grid[xi][yi + 1]) && xi > 0 && xi < 6 && !grid[xi-1][yi] && !grid[xi + 1][yi]) return;
    if(from == 'D' && (xi == 6 || grid[xi + 1][yi]) && yi > 0 && yi < 6 && !grid[xi][yi-1] && !grid[xi][yi+1]) return;
    if(from == 'L' && (yi == 0 || grid[xi][yi - 1]) && xi > 0 && xi < 6 && !grid[xi-1][yi] && !grid[xi + 1][yi]) return;
 
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = xi + dx[i];
        ny = yi + dy[i];
        if (isPossible(nx, ny) && (s[ith] == "URDL"[i] || s[ith] == '?')) {
            grid[nx][ny] = true;
            countWays(ith + 1, s, nx, ny, "URDL"[i]);
            grid[nx][ny] = false;
        }
    }
 
}
 
void solve() {
    string s;
    cin >> s;
    memset(grid, false, sizeof(grid));
    grid[0][0] = true;
    countWays(0, s, 0, 0);
    cout<<ans<<endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
