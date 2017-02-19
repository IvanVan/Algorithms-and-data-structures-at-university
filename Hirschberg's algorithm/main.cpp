#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e4 + 2;

int dp[2][N], dp1[2][N], dp2[2][N];

string s1, s2;

void calculate1 (int l1, int r1, int l2, int r2) {
    int sz2 = r2 - l2 + 1;
    int sz1 = r1 - l1 + 1;
    for (int j = 0; j <= sz2; j++)
        dp1[0][j] = 0;
    for (int i = 1; i <= sz1; i++){
        for (int j = 1; j <= sz2; j++){
            dp1[1][j] = max(dp1[0][j], dp1[1][j - 1]);
            if (s1[i + l1 - 1] == s2[j - 1 + l2]){
                dp1[1][j] = max(dp1[1][j], dp1[0][j - 1] + 1);
            }
        }
        for (int j = 0; j <= sz2; j++){
            dp1[0][j] = dp1[1][j];
        }
    }
}

void calculate2(int l1, int r1, int l2, int r2){
    int sz1 = r1 - l1 + 1;
    int sz2 = r2 - l2 + 1;
    for (int j = 0; j <= sz2; j++){
        dp2[0][j] = 0;
    }
    for (int i = 1; i <= sz1; i++){
        for (int j = 1; j <= sz2; j++){
            dp2[1][j] = max(dp2[0][j], dp2[1][j - 1]);
            if (s1[sz1 - i + l1] == s2[sz2 - j + l2]){
                dp2[1][j] = max(dp2[1][j], dp2[0][j - 1] + 1);
            }
        }
        for (int j = 0; j <= sz2; j++){
            dp2[0][j] = dp2[1][j];
        }
    }
}

void printAns (int need, int l1, int r1, int l2, int r2){
    if (l1 > r1 || l2 > r2){
        return;
    }
    if (need == 0)
        return;
    if (l1 == r1 && need == 1){
        cout << s1[l1];
        return;
    }
    if (l2 == r2 && need == 1){
        cout << s2[l2];
        return;
    }
    int m = (l1 + r1) / 2;
    calculate1(l1, m, l2, r2);
    calculate2(m + 1, r1, l2, r2);
    int sz2 = (r2 - l2 + 1);
    for (int cut = 0; cut <= (r2 - l2 + 1); cut++){
        if (dp1[0][cut] + dp2[0][sz2 - cut] == need){
            int need1 = dp1[0][cut];
            int need2 = dp2[0][sz2 - cut];
            printAns(need1, l1, m, l2, l2 + cut - 1);
            printAns(need2, m + 1, r1, l2 + cut, r2);
            break;
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> s1 >> s2;
    int sz1 = s1.size();
    int sz2 = s2.size();
    dp[0][0] = 0;
    for (int i = 1; i <= sz1; i++){
        for (int j = 1; j <= sz2; j++){
            dp[1][j] = max(dp[0][j], dp[1][j - 1]);
            if (s1[i - 1] == s2[j - 1]){
                dp[1][j] = max(dp[1][j], dp[0][j - 1] + 1);
            }
        }
        for (int j = 1; j <= sz2; j++){
            dp[0][j] = dp[1][j];
        }
    }
    int ans = dp[0][sz2];
    printAns(ans, 0, sz1 - 1, 0, sz2 - 1);
    return 0;
}
