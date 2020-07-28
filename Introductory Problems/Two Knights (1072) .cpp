#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define endl '\n'
 
void solve() {
    int n;
    cin >> n;
    if (n >= 1) {
        cout << 0 << endl;
    }
    if (n >= 2) {
        cout << 6 << endl;
    }
    if (n >= 3) {
        cout << 28 << endl;
    }
    if (n >= 4) {
        cout << 96 << endl;
    }
 
    int last = 96;
    for (int i = 5; i <= n; i++) {
        int k = i - 1;
        last += 2 * (k * k * k - ((k - 4) * 4 + 10));
        last += k * k - 2;
        last += (2 * k + 1) * k - 2;
        cout << last << endl;
    }
 
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
