#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m, k;

string a[N], b[N];

int c[260];

void radixSort (){
    m--;
    while (k > 0){
        for (int i = 0; i < 260; i++){
            c[i] = 0;
        }
        for (int i = 0; i < n; i++){
            c[(int)a[i][m]]++;
        }
        int pref = 0;
        for (int i = 0; i < 260; i++){
            int now = c[i];
            c[i] = pref;
            pref += now;
        }
        for (int i = 0; i < n; i++){
            int now = (int)a[i][m];
            b[c[now]] = a[i];
            c[now]++;
        }
        swap(a, b);
        m--;
        k--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    radixSort();
    for (int i = 0; i < n; i++){
        cout << a[i] << '\n';
    }
    return 0;
}
