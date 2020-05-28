#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
#define mod 1000000007
 
void update(int *bit, int index ,int n , int value){
    for( ; index < n; index = (index | (index +1))){
        bit[index] += value;
    }
}
void updatelr(int *bit, int l ,int r , int n , int value){
    update(bit, l , n, value);
    update(bit, r+1, n , -value);
}
int sum(int *bit, int index){
    int result = 0;
    for( ; index >=0; index = (index & (index +1)) -1){
        result += bit[index];
    }
    return result;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , t;
    cin>>n >>t;
    int *a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int *bit = new int [n +1];
    for (int j = 0; j < n + 1; ++j) {
        bit[j] = 0;
    }
    for(int i = 0; i< n; i++){
        updatelr(bit, i, i, n+1, a[i]);
    }
    while(t--){
        int o;
        cin>>o;
        if(o==1){
            int l, r, u;
            cin>>l>>r>>u;
            l--,r--;
            updatelr(bit, l, r, n+1, u);
        }
        else{
            int k;
            cin>>k;
            k--;
            cout<<sum(bit, k)<<endl;
        }
    }
    return 0;
}
