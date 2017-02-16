#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1000 * 100 + 107;

int parent[2][N], rang[N], shift = 0, n, m;

//0 - parent, 1 - inversion

void intilized (){
    for (int i = 0; i < N; i++){
        rang[i] = 0;
        parent[0][i] = i;
        parent[1][i] = 0;
    }
}

int getParent(int a){
    if (a == parent[0][a])
        return a;
    return getParent(parent[0][a]);
}

int getValue(int a, int inver){
    inver ^= parent[1][a];
    if (a == parent[0][a]){
        return inver;
    } else {
        return getValue(parent[0][a], inver);
    }
}

void unionSet (int a, int b){
    int colorA = getValue(a, 0);
    int colorB = getValue(b, 0);
    a = getParent(a);
    b = getParent(b);
    if (colorA == colorB){
        if (rang[b] > rang[a])
            swap(a, b);
        parent[1][b] ^= 1;
        parent[0][b] = a;
        if (rang[a] == rang[b])
            rang[a]++;
    } else {
        if (rang[b] > rang[a])
            swap(a, b);
        parent[0][b] = a;
        if (rang[a] == rang[b])
            rang[a]++;
    }
}

void getAns (int a, int b){
    int colorA = getValue(a, 0);
    int colorB = getValue(b, 0);
    if (colorA == colorB){
        shift++;
        shift %= n;
        puts("YES");
    } else {
        puts("NO");
    }
}

int getVal(int a){
    int ans = (a + shift) % n;
    if (ans == 0)
        ans = n;
    return ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    intilized();
    for (int i = 0; i < m; i++){
        int type, a, b;
        scanf("%d%d%d", &type, &a, &b);
        int x = getVal(a);
        int y = getVal(b);
        if (type == 0){
            unionSet (x, y);
        } else {
            getAns(x, y);
        }
    }
    return 0;
}
