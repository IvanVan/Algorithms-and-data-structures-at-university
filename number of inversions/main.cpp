#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6 + 7;

int A, B, a[N], b[N];

unsigned int cur = 0;

unsigned int nextRand24() {
    cur = cur * A + B;
    return cur>>8;
}

long long ans = 0LL;


void mergeSort (int tl, int tr){
    if (tl == tr){
        return;
    } else {
        int tm = (tl + tr) / 2;
        mergeSort(tl, tm);
        mergeSort(tm + 1, tr);
        int it1 = tl, it2 = tm + 1, pos = 0;
        while (true){
            if (it1 == tm + 1 && it2 == tr + 1){
                break;
            }
            if (it1 == tm + 1){
                b[pos] = a[it2];
                it2++;
            } else if (it2 == tr + 1){
                b[pos] = a[it1];
                it1++;
            } else {
                if (a[it1] <= a[it2]){
                    b[pos] = a[it1];
                    it1++;
                } else {
                    b[pos] = a[it2];
                    ans += tm + 1 - it1;
                    it2++;
                }
            }
            pos++;
        }
        int posA = tl;
        for (int i = 0; i < pos; i++){
            a[posA] = b[i];
            posA++;
        }
    }
}

int main()
{
    freopen("invcnt.in", "r", stdin);
    freopen("invcnt.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cin >> A >> B;
    for (int i = 0; i < n; i++){
        a[i] = nextRand24() % m;
    }
//    for (int i = 0; i < n; i++){
//        cin >> a[i];
//    }
    mergeSort(0, n - 1);
    cout << ans << endl;
    return 0;
}
