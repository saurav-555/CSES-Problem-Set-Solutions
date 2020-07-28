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
 
void solve() {
    int n;
    cin >> n;
    if ((n * (n + 1) / 2) % 2 == 0) {
        cout<<"YES"<<endl;
        if (n % 2 == 0) {
            cout << n / 2 << endl;
            for (int i = 1; i <= n / 2; i += 2) {
                cout << i << " " << (n + 1 - i) << " ";
            }
            cout<<endl;
            cout << n / 2 << endl;
            for (int i = 2; i <= n / 2; i += 2) {
                cout << i << " " << (n + 1 - i)<<" ";
            }
        } else {
            if (((n + 1) / 4) % 2 == 0) {
                cout<<n/2<<endl;
                for (int i = 3; i <= n / 2; i += 2) {
                    cout << i << " " << (n + 1 - i) << " ";
                }
                cout<<(n + 1) / 2 + (n + 1) / 4<<endl;
                cout<<n/2 + 1<<endl;
                cout<<1 <<" "<< n <<" ";
                for(int i = 2 ; i<= n / 2 ; i+=2){
                    if(i == (n + 1) / 4){
                        cout<<(n + 1) / 4 <<" "<<(n + 1) / 2 <<" ";
                    }else {
                        cout<<i <<" " << ( n + 1 - i) <<" ";
                    }
                }
                cout<<endl;
            }else{
                cout<<n/2 + 1 <<endl;
                for(int i = 1 ; i <= n / 2 ; i+=2){
                    if(i != (n + 1) / 4)
                    cout<<i <<" " << ( n + 1 - i) <<" ";
                }
                cout<<(n + 1) / 4 <<" " << ( n + 1) / 2 <<endl;
                cout<<n/2<<endl;
                cout<<(n + 1) / 2 + (n + 1) / 4 <<" ";
                for(int i = 2 ; i <= n / 2 ; i+=2){
                    cout<<i <<" " << (n + 1 - i) <<" ";
                }
            }
        }
 
    } else cout << "NO" << endl;
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
