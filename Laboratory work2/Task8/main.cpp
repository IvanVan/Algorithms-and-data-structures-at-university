#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 107, p = (int)1e6 + 3;

int parent[3][N], rang[N], zerg = 0;

//0 - parent, 1 - value, 2 - read

int getParent (int x){
    if (parent[0][x] == x)
        return x;
    return getParent(parent[0][x]);
}

void unionSet (int x, int y){
    x = getParent(x);
    y = getParent(y);
    if (x == y)
        return;
    zerg =(13 * zerg + 11) % p;
    if (rang[y] > rang[x])
        swap(x, y);
    parent[0][y] = x;
    parent[1][y] -= parent[1][x];
    if (rang[x] == rang[y])
        rang[x]++;
}

int dfs(int x, int ans){
    ans += parent[1][x];
    if (parent[0][x] == x){
        return ans;
    }
    return dfs(parent[0][x], ans);
}

void getAns (int x){
    int cut = parent[2][x];
    int sum = dfs(x, 0);
    sum -= cut;
    parent[2][x] += sum;
    printf("%d\n", max(sum, 0));
    zerg =(int)((100500 * 1LL * zerg + sum) % (p * 1LL));
}

void intialize (){
    for (int i = 0; i < N; i++){
        parent[0][i] = i;
        parent[1][i] = 0;
        rang[i] = 0;
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    intialize();
    for (int i = 0; i < m; i++){
        int type, x, y;
        scanf("%d", &type);
        if (type == 1){
            scanf("%d", &x);
            x = (x + zerg) % n;
            x = getParent(x);
            parent[1][x]++;
            zerg = (30 * zerg + 239) % p;
        } else if (type == 2){
            scanf("%d%d", &x, &y);
            x = (x + zerg) % n;
            y = (y + zerg) % n;
            unionSet(x, y);
        } else {
            scanf("%d", &x);
            x = (x + zerg) % n;
            getAns(x);
        }
    }
    return 0;
}
