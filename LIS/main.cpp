#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int N = 300 * 1000 + 101, inf = (int)1e9 + 101;

pair <int, int> dp[N];

int parent[N], a[N];

void preCalc (){
    for (int i = 0; i < N; i++){
        dp[i].F = inf;
        parent[i] = -1;
    }
    dp[0].F = -inf;
    dp[0].S = -1;
}

vector <int> ot;

void print (int last){
    if (last == -1)
        return;
    ot.push_back(a[last]);
    print(parent[last]);
}

int main()
{
//    freopen("input.txt", "r", stdin);
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);
    preCalc();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        int now = a[i];
        int l = 0, r = N;
        while (r - l > 1){
            int m = (l + r) / 2;
            if (dp[m].F > now){
                r = m;
            } else {
                l = m;
            }
        }
        l++;
        if (dp[l].F > now && dp[l - 1].F < now){
            dp[l].F = now;
            parent[i] = dp[l - 1].S;
            ans = max(ans, l);
            dp[l].S = i;
        }
    }
//    ot.push_back(dp[ans].F);
    print(dp[ans].S);
    cout << ot.size() << endl;
    for (int i = (int)ot.size() - 1; i >= 0; i--)
        cout << ot[i] << ' ';
    return 0;
}
