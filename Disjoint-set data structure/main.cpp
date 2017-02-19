#include <bits/stdc++.h>

using namespace std;
const int N = 300 * 1000 + 2;

int parent[N][4], rang[N];

//main, min, max, kol;

int find_parent (int a){
    if (parent[a][0] == a){
        return a;
    }
    a = find_parent(parent[a][0]);
    return a;
}

void calculate (int a, int b){
    parent[a][1] = min(parent[a][1], parent[b][1]);
    parent[a][2] = max(parent[a][2], parent[b][2]);
    parent[a][3] += parent[b][3];
}

void add (int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if (a != b){
        if (rang[a] > rang[b]){
            parent[b][0] = a;
            calculate(a, b);
        } else if (rang[b] > rang[a]) {
            parent[a][0] = b;
            calculate(b, a);
        } else {
            parent[a][0] = b;
            calculate(b, a);
            rang[a]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("dsu.in", "r", stdin);
    freopen("dsu.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        parent[i][0] = i;
        parent[i][1] = i;
        parent[i][2] = i;
        parent[i][3] = 1;
    }
    string s;
    while (cin >> s){
        if (s == "union"){
            int a, b;
            cin >> a >> b;
            add(a, b);
        } else {
            int a;
            cin >> a;
            a = find_parent(a);
            cout << parent[a][1] << ' ' << parent[a][2] << ' ' << parent[a][3] << '\n';
        }
    }
    return 0;
}
