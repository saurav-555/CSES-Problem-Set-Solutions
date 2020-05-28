#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
#define MOD 1000000007
#define MAX 100005
 
int arr[MAX];
int  *seg_tree;
void buildSeg(const int *a , int in , int s, int e){
    if(s == e){
        seg_tree[in] = 1;
        return;
    }
    int mid = (s + e) / 2;
    buildSeg(a, 2*in + 1, s, mid);
    buildSeg(a, 2*in + 2, mid + 1, e);
    seg_tree[in] = seg_tree[2*in + 1] + seg_tree[2*in + 2];
}
int  updateSeg(int in , int s, int e , int index_value){
    if(s == e){
        seg_tree[in] = 0;
        return s;
    }
    int mid = (s + e) / 2;
    int k ;
    if(index_value <= seg_tree[2*in + 1] ){
        k = updateSeg(2*in  + 1, s , mid , index_value);
    }else {
        k = updateSeg(2*in + 2, mid + 1, e, index_value - seg_tree[2*in + 1]);
    }
    seg_tree[in] = seg_tree[2*in + 1] + seg_tree[2*in + 2];
    return k;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin>>n;
    t= n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int seg_size = 2 * (int)pow(2, ceil(log2(n))) - 1;
    seg_tree = new int[seg_size];
    for (int j = 0; j < seg_size; ++j) {
        seg_tree[j] = 0;
    }
    buildSeg(a, 0 , 0 , n-1);
    while(t--){
        int index;
        cin>>index;
        cout<<a[updateSeg(0, 0, n-1 , index)]<<" ";
    }
    return 0;
}
