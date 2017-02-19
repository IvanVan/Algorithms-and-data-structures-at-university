#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 101, maxi = 65600, con = (1<<16) - 1;

int a, b, c[maxi], n;

unsigned int x[N], y[N];

unsigned int cur = 0;
unsigned int nextRand24() {
    cur = cur * a + b;
    return cur>>8;
}
unsigned int nextRand32() {
    unsigned int a = nextRand24(), b = nextRand24();
    return (a<<8) ^ b;
}

int getDigit (int i, int how){
    int q = x[i];
    if (how == 1){
        q >>= 16;
    }
    return (q & con);
}

void radixSort (){
    for (int w = 0; w < 2; w++){
        for (int i = 0; i < maxi; i++){
            c[i] = 0;
        }
        for (int i = 0; i < n; i++){
            int digit = getDigit(i, w);
            c[digit]++;
        }
        int pref = 0;
        for (int i = 0; i < maxi; i++){
            int now = c[i];
            c[i] = pref;
            pref += now;
        }
        for (int i = 0; i < n; i++){
            int now = getDigit(i, w);
            y[c[now]] = x[i];
            c[now]++;
        }
        swap(x, y);
    }
}



int main()
{
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    cin >> n;
    for (int i = 0; i < t; i++){
        unsigned long long ans = 0;
        cin >> a >> b;
        for (int j = 0; j < n; j ++){
            x[j] = nextRand32();
        }
        radixSort();
        for (int j = 0; j < n; j++){
            ans += x[j] * 1LL * (j + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}
