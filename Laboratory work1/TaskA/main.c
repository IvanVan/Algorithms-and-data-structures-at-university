#include <bits/stdc++.h>
#include <malloc.h>

using namespace std;
int sz = 2, have = 1;

int* a = (int*)(malloc(2 * sizeof(int)));

void add (int x){
    if (have == sz + 1){
        int* b = (int*)(malloc(2 * sz * sizeof(int)));
        for (int i = 0; i < sz; i++){
            b[i] = a[i];
        }
        sz *= 2;
        free(a);
        a = b;
        a[have - 1] = x;
    } else {
        a[have - 1] = x;
    }
    have++;
}

void er (){
    printf("%d\n", a[have-2]);
    have--;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("stack1.in", "r", stdin);
    freopen("stack1.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++){
        char c;
        scanf("%c", &c);
        if (c == '-'){
            er();
        } else {
            int x;
            scanf(" %d", &x);
            add(x);
        }
        scanf("\n");
    }
    return 0;
}
