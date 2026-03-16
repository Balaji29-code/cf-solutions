#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9 + 7;

void solve(){
    int n,ax,ay,bx,by;
    cin >> n >> ax >> ay >> bx >> by;
    map<int,set<int>> mp;
    vector<pair<int,int>> pa(n);
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        pa[i].first = x;
    }

    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        pa[i].second = x;
    }

    for(int i = 0 ; i < n ; i++){
        int x = pa[i].first;
        int y = pa[i].second;
        mp[x].insert(y);
    }

    int dp0 = 0;
    int dp1 = 0;
    int b = ay;
    int t = ay;
    int prevx = ax;

    for(auto [x,v] : mp){
        int prev0 = dp0;
        int prev1 = dp1;

        int xdis = x - prevx;

        int low = *v.begin();
        int high = *v.rbegin();

        dp0 = xdis + min(prev0 + abs(high-b) + (high-low),
                        prev1 + abs(high-t) + (high-low));

        dp1 = xdis + min(prev0 + abs(low-b) + (high-low),
                        prev1 + abs(low-t) + (high-low));

        prevx = x;
        b = low;
        t = high;
    }
    int f1 = dp0 + bx - prevx + abs(by-b);
    int f2 = dp1 + bx - prevx + abs(by-t);
    cout << min(f1,f2) << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
        solve();
}