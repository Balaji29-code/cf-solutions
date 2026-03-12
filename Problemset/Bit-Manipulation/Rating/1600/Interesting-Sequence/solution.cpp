#include "bits/stdc++.h"
using namespace std;
#define int long long 

void solve(){
    int n, x;
    cin >> n >> x;

    if(n == x){
        cout << n << endl;
        return;
    }
    vector<int> pos;
    int var = n;
    int ptr = 0;

    while(var > 0){
        if(var & 1) pos.push_back(ptr);
        ptr++;
        var >>= 1;
    }

    int si = pos.size();

    for(int cur = 0; cur < si; cur++){
        int check = n;
        int loc = pos[cur];
        check = check & (~((1LL << loc) - 1));

        if(cur < si - 1){
            if(pos[cur+1] != pos[cur] + 1){
                check += (1LL << (pos[cur] + 1));
                check -= (1LL << pos[cur]);

                if((check & n) == x){
                    cout << check << endl;
                    return;
                }
            }
        }
        else{
            check += (1LL << (pos[cur] + 1));
            check -= (1LL << pos[cur]);

            if((check & n) == x){
                cout << check << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
        solve();
}