#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 10;

struct snowMan {
    int val;
    snowMan *pref;

    snowMan(): val(0), pref(NULL){}
};

snowMan* a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) a[i] = new snowMan();
    for (int i = 1; i <= n; i++){
        int t, m;
        cin >> t >> m;
        if (m == 0){
            a[i] -> pref = a[t] -> pref -> pref;
            a[i] -> val = a[t] -> pref -> val;
        } else {
            a[i] -> pref = a[t];
            a[i] -> val = a[t] -> val;
            a[i] -> val += m;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        ans += a[i] -> val * 1LL;
    }
    cout << ans << endl;
    return 0;
}
