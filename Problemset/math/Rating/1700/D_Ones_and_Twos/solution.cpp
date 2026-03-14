#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9 + 7;

void solve(){
    int n,q;
    cin >> n >> q;

    vector<int> a(n+1);
    set<int> s;
    int sum = 0;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        sum += a[i];
        if(a[i] == 1) s.insert(i);
    }

    while(q--){
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int check;
            cin >> check;

            if (check > sum) {
                cout << "NO\n";
                continue;
            }

            if ((sum - check) % 2 == 0) {
                cout << "YES\n"; 
            } 
            else {
                if (s.empty()) {
                    cout << "NO\n";
                } else {
                    int x = *s.begin();
                    int y = *s.rbegin();

                    long long s1 = sum - 2LL * (x - 1) - 1;
                    long long s2 = sum - 2LL * (n - y) - 1;

                    if (check <= max(s1, s2)) cout << "YES\n";
                    else cout << "NO\n";
                }
            }
        }
        else{
            int idx,val;
            cin >> idx >> val;

            if(a[idx] == val) continue;

            sum += val - a[idx];

            if(a[idx] == 1) s.erase(idx);
            if(val == 1) s.insert(idx);

            a[idx] = val;
        }
    }
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
        solve();
}