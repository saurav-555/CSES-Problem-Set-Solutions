#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
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
    ll n;
    cin>>n;
    while(true){
    	cout<<n<<" ";
    	if(n == 1)
    		break;
    	if(n % 2 == 0)
    		n/=2;
    	else n = 3 * n + 1;
    }
    cout<<endl;
}
 
int main() {
    
 //    #ifndef ONLINE_JUDGE
	// freopen("input.txt" , "r" , stdin);
	// freopen("output.txt" ,"w" , stdout);
	// #endif
 
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
