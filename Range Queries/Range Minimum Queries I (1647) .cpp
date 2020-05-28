#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
 
int min_in_seg(int *seg, int l , int h , int tl ,int th, int index){
 
    if(l > th || h < tl){
        return LONG_LONG_MAX;
    }
    if(l<= tl && h >=th){
        return seg[index];
    }
    int mid = (tl + th) /2;
    return min(min_in_seg(seg, l, h, tl , mid , 2*index + 1) , min_in_seg(seg, l , h, mid + 1, th , 2*index + 2));
}
 
int create_seg(const int *a , int *seg , int al, int ah , int index ){
    if(al == ah){
        seg[index] = a[al];
        return seg[index];
    }
    int mid = (al + ah) /2;
    seg[index] = min(create_seg(a, seg, al , mid , 2*index + 1), create_seg(a, seg, mid + 1, ah , 2*index + 2));
    return seg[index];
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
    int seg_size = 2 * (int) pow(2, ceil(log2(n))) -1;
    int *seg = new int [seg_size];
    create_seg(a , seg,  0 , n-1 , 0);
    // setting high values;
    while(t--){
        int l , r;
        cin>>l>>r;
        l--, r--;
        cout<<min_in_seg(seg, l , r, 0, n-1, 0)<<endl;
    }
    return 0;
 
}
