#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
#define endl '\n'
 
int sum_in_seg(int *seg, int l , int h , int tl ,int th, int index){
 
    if(l > th || h < tl){
        return LONG_LONG_MAX;
    }
    if(l<= tl && h >=th){
        return seg[index];
    }
    int mid = (tl + th) /2;
    return min(sum_in_seg(seg, l, h, tl , mid , 2*index + 1) , sum_in_seg(seg, l , h, mid + 1, th , 2*index + 2));
 
}
 
int create_seg(const int *a , int *seg , int al, int ah , int index ){
    if(al == ah){
        seg[index] = a[al];
        return seg[index];
    }
    int mid = (al + ah) /2;
    seg[index] = min(create_seg(a, seg, al , mid , 2*index + 1) ,create_seg(a, seg, mid + 1, ah , 2*index + 2));
 
    return seg[index];
}
void update_seg(int *seg, int ind , int value, int tl, int th, int index){
    if(ind < tl || ind > th) {
        return;
    }
    if(tl == th){
        seg[index] = value;
    }
    if(tl!=th){
        int mid = (tl + th) /2;
        update_seg(seg, ind, value, tl , mid, 2*index + 1);
        update_seg(seg, ind, value, mid + 1, th, 2*index + 2);
        seg[index] = min(seg[2*index + 1] , seg[2*index + 2]);
    }
 
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
        int o ,l,r;
        cin>>o;
        if(o==1){
            cin>>l>>r;
            l--;
            a[l] = r;
            update_seg(seg, l, r, 0, n-1, 0);
        }
        else {
            cin>>l>>r;
            l--,r--;
            cout<<sum_in_seg(seg, l, r, 0, n-1, 0)<<endl;
        }
    }
    return 0;
 
}
