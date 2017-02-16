#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = (int)5e4 + 100;

int parent[N], rang[N];

int find_parent (int a){
    if (parent[a] == a){
        return a;
    }
    a = find_parent(parent[a]);
    return a;
}

void add (int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if (a != b){
        if (rang[a] > rang[b]){
            parent[b] = a;
        } else if (rang[b] > rang[a]) {
            parent[a] = b;
        } else {
            parent[b] = a;
            rang[a]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream cin ("cutting.in");
    ofstream cout ("cutting.out");
    for (int i = 0; i < N; i++){
        parent[i] = i;
        rang[i] = 0;
    }
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
    }
    vector <pair <string, pair <int, int> > > zap;
    for (int i = 0; i < k; i++){
        string type;
        int u, v;
        cin >> type >> u >> v;
        zap.pb(mp(type, mp(u, v)));
    }
    vector <bool> ans;
    for (int i = zap.size() - 1; i >= 0; i--){
        int u = zap[i].S.F, v = zap[i].S.S;
        if (zap[i].F == "ask"){
            u = find_parent(u);
            v = find_parent(v);
            if (v == u){
                ans.pb(true);
            } else {
                ans.pb(false);
            }
        } else {
            add(u, v);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--){
        if (ans[i]){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
