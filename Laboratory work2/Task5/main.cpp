#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 10;

int vertex[N], rang[N], parent[N], n , q;

int getRightBoard(int i){
    if (vertex[i] == i)
        return i;
    return vertex[i] = getRightBoard(vertex[i]);
}

int getParent(int x){
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

void union1 (int x, int y){
    x = getParent(x);
    y = getParent(y);
    if (x == y)
        return;
    if (rang[y] > rang[x])
        swap(x, y);
    parent[y] = x;
    if (rang[x] == rang[y])
        rang[x]++;
}

void union2 (int x, int y){
    if (x == y)
        return;
    for (int i = x; i < y; i++){
        int rightBoard = getRightBoard(i);
        if (rightBoard == i){
            vertex[i] = i + 1;
            union1(i, y);
        } else {
            if (getRightBoard(i) == i + 1)
                continue;
            else
                i = getRightBoard(i) - 1;
        }
    }
}

void intelized(){
    for (int i = 1; i <= n; i++){
        vertex[i] = i;
        rang[i] = 0;
        parent[i] = i;
    }
}

void getAns (int x, int y){
    x = getRightBoard(x);
    y = getRightBoard(y);
    if (x == y){
        puts("YES");
        return;
    }
    x = getParent(x);
    y = getParent(y);
    if (x == y)
        puts("YES");
    else
        puts("NO");
}

int main()
{
//    freopen("input.txt", "r", stdin);
    freopen("restructure.in", "r", stdin);
    freopen("restructure.out", "w", stdout);
    scanf("%d%d", &n, &q);
    intelized();
    for (int i = 0; i < q; i++){
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        if (type == 2){
            union2(x, y);
        } else if (type == 1){
            union1(x, y);
        } else {
            getAns(x, y);
        }
    }
    return 0;
}
