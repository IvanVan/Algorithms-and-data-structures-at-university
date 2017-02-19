#include <bits/stdc++.h>

using namespace std;
int mas[100500] , cost[100500];
int dp[1100][11000];
vector < int > ans;
void print ( int now , int ves ){
    if ( now <= 0 || ves <= 0 ){
        return;
    }
    if ( dp[now][ves] == dp[now-1][ves] ){
        print(now-1,ves);
    } else {
        ans.push_back(now);
        ves-=mas[now];
        now--;
        print(now,ves);
    }
}

int main()
{
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    int n , m;
    scanf("%d%d" , &n , &m );
    for ( int i = 1 ; i <= n ; i++){
        scanf("%d" , &mas[i]);
    }
    for ( int i = 1; i <= n ; i++){
        scanf("%d" , &cost[i]);
    }
    for ( int i = 1 ; i <= n ; i++){
        for ( int j = 1 ; j <= m ; j++){
            dp[i][j] = dp[i-1][j];
            if ( j >= mas[i] ){
                dp[i][j] = max(dp[i][j] , dp[i-1][j - mas[i]] + cost[i]);
            }
        }
    }
    print( n , m);
    reverse(ans.begin() , ans.end());
    printf("%d\n", ans.size());
    for ( int i = 0 ; i < (int)ans.size() ; i++){
        printf("%d " , ans[i]);
    }
    return 0;
}
