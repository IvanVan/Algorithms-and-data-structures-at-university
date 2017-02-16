#include <bits/stdc++.h>
#include <malloc.h>

using namespace std;

struct q {
    int val;

    q* next;

    q(int x): val(x), next(NULL){}
};

q* first = new q(0);

q* last = first;

void add (int x){
    if (first -> next == NULL){
        last = new q(x);
        first -> next = last;
    } else {
        q* now = new q(x);
        last -> next = now;
        last = now;
    }
}

void er (){
    printf("%d\n", first -> next -> val);
    first = first -> next;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    freopen("queue2.in", "r", stdin);
    freopen("queue2.out", "w", stdout);
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
            er();
        }
        scanf("\n");
    }
    return 0;
}
