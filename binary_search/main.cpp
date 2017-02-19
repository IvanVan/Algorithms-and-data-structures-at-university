#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 117;

int a[N], n;

int getLeftBoard (int val){
    int  l = -1, r = n - 1;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (a[m] >= val){
            r = m;
        } else {
            l = m;
        }
    }
    if (a[r] != val)
        return -1;
    return r + 1;
}

int getRightBoard (int val){
    int l = 0, r = n;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (a[m] <= val){
            l = m;
        } else {
            r = m;
        }
    }
    if (a[l] != val)
        return -1;
    return l + 1;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        int type;
        scanf("%d", &type);
        int l = getLeftBoard(type);
        int r = getRightBoard(type);
        printf("%d %d\n", l, r);
    }
    return 0;
}
