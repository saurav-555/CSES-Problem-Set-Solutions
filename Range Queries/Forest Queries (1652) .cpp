#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
#define endl '\n'
void updateBit2d(int **bit2d, int y, int x , int n, int value){
    for(int i = y; i < n; i = i | (i +1)){
        for(int j = x; j < n; j = j | (j +1) ){
            bit2d[i][j] += value;
        }
    }
}
 
int sum(int **bit2d, int y,int x ){
    int result = 0;
    for(int i = y; i >= 0; i= (i & i + 1) -1){
        for(int j = x ; j>=0; j = (j & j + 1) -1){
            result += bit2d[i][j];
        }
    }
    return result;
}
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin>>n>>t;
    int **bit2d = new int * [n];
    for(int i = 0; i< n; i++){
        bit2d[i] = new int[n];
    }
    for(int i = 0; i< n; i++){
        for (int j = 0; j < n; ++j) {
            bit2d[i][j] = 0;
        }
    }
    for(int i = 0 ; i< n; i++){
        string x;
        cin>>x;
        for(int j = 0; j < n ; j++){
            if(x[j] == '*'){
                updateBit2d(bit2d, i , j, n , 1);
            }
        }
    }
    while(t--){
        int result = 0;
        int y1 , x1, y2, x2;
        cin>>y1>>x1>>y2>>x2;
        y1--, x1--, y2--, x2--;
        if (y2 < y1 || x2 < x1) {
            swap(y2, y1);
            swap(x2, x1);
        }
        result = sum(bit2d, y2, x2);
        if(x1 == 0 && y1== 0){
 
        }
        else if(y1==0){
            result -= sum(bit2d,y2, x1-1);
        }
        else if(x1== 0){
            result -= sum(bit2d, y1 -1, x2);
        } else{
            result +=sum(bit2d, y1-1, x1-1);
            result -= sum(bit2d,y2, x1-1);
            result -= sum(bit2d, y1 -1, x2);
        }
        cout<<result<<endl;
    }
    return 0;
}
