#include<iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using u128 = __uint128_t;
 
#define int long long
#define index_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define atIndex find_by_order
#define indexOf order_of_key
#define MOD 1000000007
#define MAX 200005
 
int arr[MAX];
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n , t;
    cin>>n>>t;
    index_set tt;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
        tt.insert(arr[i]);
    }
    while(t--){
        char c;
        cin>>c;
        if(c=='?'){
            int l , r;
            cin>>l>>r;
            cout<<tt.indexOf(r + 1) - tt.indexOf(l)<<endl;
        }else {
            int k , x;
            cin>>k>>x;
            k--;
            tt.erase(tt.atIndex(tt.indexOf(arr[k])));
            tt.insert(x);
            arr[k] = x;
        }
    }
    return 0;
}
