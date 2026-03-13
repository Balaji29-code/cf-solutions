#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long 
const int MOD = 1e9 + 7;

void solve(){
    int a,b;
    cin >> a >> b;
    int x = (a-b);
    if(x < 0){
        cout << -1 << endl;
        return;
    }

    int xf = (x>>=1);
    int y = xf^b;
    if(xf+y == a && xf^y == b) cout << x << " " << y << endl;
    else cout << -1 << endl;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
}