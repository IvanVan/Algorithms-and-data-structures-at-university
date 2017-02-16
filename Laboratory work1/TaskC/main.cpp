#include <bits/stdc++.h>
#include <malloc.h>

using namespace std;

int* a = (int*)(malloc(2 * sizeof(int)));

int sz = 2, it1 = 0, it2 = 0;

void add (int x){
    if (it2 == sz && it1 != 0){
        it2 = 0;
    }
    if (it1 == it2 && it2 != 0){
        int* b = (int*)(malloc(2 * sz * sizeof(int)));
        int j = 0;
        for (int i = it1; i < sz; i++, j++){
            b[j] = a[i];
        }
        for (int i = 0; i < it2; i++, j++){
            b[j] = a[i];
        }
        a = b;
        a[sz] = x;
        it1 = 0;
        it2 = sz + 1;
        sz *= 2;
        return;
    }
    if (it1 == 0 && it2 == sz){
        int* b = (int*)(malloc(2 * sz * sizeof(int)));
        int j = 0;
        for (int i = it1; i < sz; i++, j++){
            b[j] = a[i];
        }
        a = b;
        a[sz] = x;
        it1 = 0;
        it2 = sz + 1;
        sz *= 2;
    } else {
        a[it2] = x;
        it2++;
    }
}

int get_dist (){
    if (it2 > it1){
        return (it2 - it1);
    } else {
        return (sz - it1 + it2);
    }
}

int dist = 0;

void er (){
    printf("%d\n", a[it1]);
    it1++;
    if (it1 == it2){
        it1 = 0;
        it2 = 0;
    }
    if (it1 == sz){
        it1 = 0;
    }
    dist = get_dist();
    if (sz / get_dist() == 4){
        int* b = (int*)(malloc((sz /2) * sizeof(int)));
        int j = 0;
        if (it2 > it1){
            for (int i = it1; i < it2; i++, j++){
                b[j] = a[i];
            }
        } else {
            for (int i = it1; i < sz; i++, j++){
                b[j] = a[i];
            }
            for (int i = 0; i < it2; i++, j++){
                b[j] = a[i];
            }
        }
        a = b;
        it1 = 0;
        it2 = j;
        sz /= 2;
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    freopen("queue1.in", "r", stdin);
    freopen("queue1.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++){
        char c;
        int x;
        scanf("%c", &c);
        if (c == '+'){
            scanf(" %d", &x);
            add(x);
        } else {
            er();
        }
        if (i != n - 1){
            scanf("\n");
        }
    }
    return 0;
}
