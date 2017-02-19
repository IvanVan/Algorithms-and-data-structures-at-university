#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int N = 20, maxi = (int)1e6;

const long long inf = 1000000000000;

long long dp[maxi][N], g[N][N];

int main()
{
//    freopen("input.txt", "r", stdin);
    freopen("salesman.in", "r", stdin);
    freopen("salesman.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            g[i][j] = inf;
        }
    }
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u][v] = w;
        g[v][u] = w;
    }
    int mask = (1<<n);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < maxi; j++){
            dp[j][i] = inf;
        }
    }
    for (int i = 0; i < n; i++){
        int mas = (1<<i);
        dp[mas][i] = 0;
    }
    for (int i = 1; i < mask; i++){
        int countOne = 0;
        for (int j = 0; j < n; j++){
            int nowBit = i & (1<<j);
            if (nowBit != 0){
                countOne++;
            }
        }
        for (int last = 0; last < n; last++){
            for (int now = 0; now < n; now++){
                int haveNow = i & (1<<now);
                int haveLast = i & (1<<last);
                if (now == last || haveLast == 0 || haveNow != 0){
                    continue;
                }
                int nowMask = i + (1<<now);
                dp[nowMask][now] = min(dp[nowMask][now], dp[i][last] + g[last][now]);
            }
        }
    }
    mask--;
    long long ans = inf;
    for (int i = 0; i < n; i++){
        ans = min(ans, dp[mask][i]);
    }
    if (ans == inf){
        cout << "-1";
    } else {
        cout << ans;
    }
    return 0;
}
