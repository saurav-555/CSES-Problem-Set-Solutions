#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
#define mod 1000000007
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , t;
    cin>>n>>t;
    int *a = new int[n];
    int *pre = new int[n+1];
    pre[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for(int i= 1; i<=n ; i++){
        pre[i] = pre[i-1] ^ a[i-1];
    }
    while(t--){
        int l , r;
        cin>>l>>r;
        cout<<(pre[r]^pre[l-1])<<endl;
    }
    return 0;
}
