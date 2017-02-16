#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 500 * 1000 + 100;
 
int a[N][2], sz = 1, operation[N];
 
void changeVertex (int i1, int i2){
    swap(a[i1][0], a[i2][0]);
    swap(a[i1][1], a[i2][1]);
    operation[a[i1][1]] = i1;
    operation[a[i2][1]] = i2;
}
 
void sif_down (int i){
    if (i * 2 < sz){
        int mi = min(a[i][0], a[i * 2][0]);
        if (i * 2 + 1 < sz){
            mi = min(a[i * 2 + 1][0], mi);
            if (mi == a[i * 2 + 1][0]){
                changeVertex(i, i * 2 + 1);
                sif_down(i * 2 + 1);
            }
        }
        if (mi == a[i * 2][0]){
            changeVertex(i, i * 2);
            sif_down(i * 2);
        }
    }
}
 
void er (){
    if (sz == 1){
        cout << "*\n";
    } else {
        sz--;
        cout << a[1][0] << '\n';
        changeVertex(1, sz);
        sif_down(1);
    }
}
 
void sif_up (int i){
    if (i == 1){
        return;
    }
    if (a[i][0] < a[i / 2][0]){
        changeVertex(i, i / 2);
        sif_up(i / 2);
    }
}
 
void add (int x, int numberOfOperation){
    a[sz][0] = x;
    a[sz][1] = numberOfOperation;
    operation[numberOfOperation] = sz;
    sz++;
    sif_up(sz - 1);
}
 
void decreaseKey(int numberOfOperation, int val){
    int numberOfVertex = operation[numberOfOperation];
    if (val < a[numberOfVertex][0]){
        a[numberOfVertex][0] = val;
        sif_up(numberOfVertex);
    } else {
        a[numberOfVertex][0] = val;
        sif_down(numberOfVertex);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    string s;
    int kol = 1;
    while (cin >> s){
        if (s == "push"){
            int x;
            cin >> x;
            add(x, kol);
        } else if (s == "extract-min"){
            er();
        } else {
            int numberOfOperation, val;
            cin >> numberOfOperation >> val;
            decreaseKey(numberOfOperation, val);
        }
        kol++;
    }
    return 0;
}
