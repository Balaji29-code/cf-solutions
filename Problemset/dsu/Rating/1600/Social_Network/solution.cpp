#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9 + 7;


struct DSU{
    vector<int> par;
    vector<int> si;
    int siz;
    DSU(int n){
        par.resize(n);
        si.resize(n);
        siz = n;
        for(int i = 0 ; i < n ; i++){
            si[i] = 1;
            par[i] = i;
        }
    }
    int find(int a){
        if(par[a] == a) return a;
        return par[a] = find(par[a]);
    }
    int merge(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return 0;

        if(si[a] < si[b]) swap(a,b);

        par[b] = a;
        si[a] += si[b];
        return 1;
    }
    int ans(int ext){
        vector<int> comp_sizes;
        for(int i = 0; i < siz; i++){
            if(par[i] == i) comp_sizes.push_back(si[i]);
        }

        sort(comp_sizes.rbegin(), comp_sizes.rend());

        int count = 0;
        for(int i = 0; i < comp_sizes.size(); i++){
            count += comp_sizes[i];
            if(ext == 0) break;
            ext--;
        }

        return count - 1; 
    }
};

void solve(){
    int n,d;
    cin >> n >> d;
    int ext = 0;
    DSU dsu = DSU(n);
    for(int i = 0 ; i < d ; i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        int ch = dsu.merge(x,y);
        if(ch == 0) ext++;
        int cur = dsu.ans(ext);
        cout << min(cur,i+1) << endl;
    }

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
}