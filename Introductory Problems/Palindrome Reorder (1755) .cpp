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
    string x;
    cin>>x;
    int a[26] = {0};
    int odd = 0 , even = 26;
    for(auto i : x){
        if(a[i-'A'] % 2 == 0)
            even --;
        else
            odd--;
        a[i-'A']++;
        if(a[i-'A'] % 2 == 1)
            odd++;
        else even++;
    }
    if(x.size() % 2 == 0){
        if(odd == 0){
            for(int i = 0 ; i < 26 ; i++){
                int k = a[i] / 2;
                for(int j = 0 ; j < k; j++ ){
                    cout<<(char)(i + 'A');
                }
            }
            for(int i = 25 ; i >= 0 ; i--){
                int k = a[i] / 2;
                for(int j = 0; j < k ; j++){
                    cout<<(char)( i + 'A');
                }
            }
            cout<<endl;
        }else cout<<"NO SOLUTION"<<endl;
    }else {
        if(odd == 1){
            for(int i = 0 ; i < 26 ; i++){
                if(a[i] % 2 == 0){
                    int k = a[i] / 2;
                    for(int j = 0 ; j < k; j++ ){
                        cout<<(char)(i + 'A');
                    }
                }
            }
            for(int i = 0 ; i < 26 ; i++){
                if(a[i] % 2 == 1){
                    for(int j = 0 ; j < a[i] ; j++){
                        cout<<(char)(i + 'A');
                    }
                }
            }
            for(int i = 25 ; i >= 0 ; i--){
                if(a[i] % 2 == 0){
                    int k = a[i] / 2;
                    for(int j = 0 ; j < k; j++ ){
                        cout<<(char)(i + 'A');
                    }
                }
            }
        }else cout<<"NO SOLUTION"<<endl;
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
