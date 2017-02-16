#include <bits/stdc++.h>

using namespace std;

const int N = 300000;

int t[4 * N], a[N];

void build (int v, int tl, int tr){
    if (tl == tr){
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v + v, tl, tm);
        build(v + v + 1, tm + 1, tr);
        t[v] = t[v + v] + t[(v + v) + 1];
    }
}

int get_sum (int v, int tl, int tr, int l, int r){
    if (l > r){
        return 0;
    }
    if (l == tl  && r == tr){
        return t[v];
    } else {
        int tm = (tl + tr) / 2;
        return get_sum(v + v, tl, tm, l, min(tm, r)) + get_sum(v + v + 1, tm + 1, tr, max(tm + 1, l), r);
    }
}

void modify (int v, int tl, int tr, int pos, int val){
    if (tl == tr){
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm){
            modify(v + v, tl, tm, pos, val);
        } else {
            modify(v + v + 1, tm + 1, tr, pos, val);
        }
        t[v] = t[v + v] + t[v + v + 1];
    }
}

int find_place (int v, int tl, int tr, int need){
    if (tl == tr){
        return tl;
    } else {
        int tm = (tl + tr) / 2;
        if (t[v + v] >= need){
            return find_place(v + v, tl, tm, need);
        } else {
            return find_place(v + v + 1, tm + 1, tr, need - t[v + v]);
        }
    }
}

int main()
{
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        a[i] = 1;
    }
    build (1, 0, n - 1);
    for (int i = 0; i < n; i++){
        int cur;
        cin >> cur;
        if (a[cur - 1] == 1){
            a[cur - 1] = 0;
            modify(1, 0, n - 1, cur - 1, 0);
            cout << cur << ' ';
        } else {
            int need = get_sum(1, 0, n - 1, 0, cur - 1);
            int now_place;
            if (get_sum(1, 0, n - 1, cur - 1, n - 1) == 0){
                now_place = find_place(1, 0, n - 1, 1);
            } else {
                now_place = find_place(1, 0, n - 1, need + 1);
            }
            a[now_place] = 0;
            modify(1, 0, n- 1, now_place, 0);
            cout << now_place + 1 << ' ';
        }
    }
    return 0;
}
