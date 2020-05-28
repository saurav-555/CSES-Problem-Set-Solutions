#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
#define max 200005
 
int last_visited[max];
 
struct data{
    int index;
    int value;
    int val;
};
struct query{
    int l;
    int r;
    int index;
};
 
int count(const int *bit , int r) {
    int res= 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += bit[r];
    return res;
}
void update(int *bit , int index, int n, int value){
    for(int i = index; i < n; i = i | (i + 1)){
        bit[i] +=value;
    }
}
bool compare_q(const query &x, const query &y){
    return x.r < y.r;
}
bool compare_a_value(const data &x, const data &y){
    return x.value < y.value;
}
bool compare_a_index(const data &x, const data &y){
    return x.index < y.index;
}
 
void set_arr(data *arr, int n){
    arr[0].val = 0;
    for(int i = 1 ; i<n ; i++){
        if(arr[i].value != arr[i-1].value){
            arr[i].val = arr[i-1].val + 1;
        }
        else arr[i].val = arr[i-1].val;
    }
}
void solve_query(data *arr, int n, query *que , int q){
    memset(last_visited, -1, sizeof(last_visited));
    int bit[n], ans[q];
    memset(bit, 0, sizeof(bit));
    int query_index = 0;
 
    for(int i = 0; i< n; i++){
        if(last_visited[arr[i].val] !=-1){
            update(bit, last_visited[arr[i].val], n, -1);
        }
 
        last_visited[arr[i].val] = i;
        update(bit, i, n, 1);
        while(query_index < q && que[query_index].r == i){
            ans[que[query_index].index] = count(bit , que[query_index].r ) - count(bit, que[query_index].l -1);
            query_index ++;
        }
    }
    for(int i = 0; i< q; i++){
        cout<<ans[i]<<endl;
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin>>n>>q;
    data *arr = new data[n];
    for (int i = 0; i < n; ++i) {
        arr[i].index = i;
        cin>>arr[i].value;
    }
    auto *que = new query[q];
    for (int j = 0; j < q; ++j) {
        int l, r;
        cin>>l>>r;
        que[j].l = l-1;
        que[j].r = r-1;
        que[j].index = j;
    }
 
    sort(arr + 0, arr + n, compare_a_value);
 
    set_arr(arr, n);
 
    sort(arr + 0, arr + n, compare_a_index);
 
    sort(que + 0, que + q, compare_q);
 
 
    solve_query(arr, n, que, q);
    return 0;
}
