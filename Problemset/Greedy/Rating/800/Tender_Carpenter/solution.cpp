#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >>a[i];
    }
    for(int i = 0 ; i < n-1 ; i++){
        if(2*a[i] > a[i+1] && 2*a[i+1] > a[i]){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
        solve();
}