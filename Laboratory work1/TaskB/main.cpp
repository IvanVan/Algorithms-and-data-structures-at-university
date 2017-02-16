#include <bits/stdc++.h>
#include <malloc.h>

using namespace std;

struct List {
    int val;

    List *predoc;

    List(int x): val(x), predoc(NULL){}
};

List* root = new List(10);

void add (int x){
    List* now = new List(x);
    now -> predoc = root;
    root = now;
}

void pop (){
    printf("%d\n", root -> val);
    root = root -> predoc;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    freopen("stack2.in", "r", stdin);
    freopen("stack2.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++){
        char c;
        scanf("%c", &c);
        if (c == '+'){
            int x;
            scanf(" %d", &x);
            add(x);
        } else {
            pop();
        }
        if (i != n - 1){
            scanf("\n");
        }
    }
    return 0;
}
