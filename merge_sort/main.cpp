#include <bits/stdc++.h>

using namespace std;

const int N = 300 * 1000 + 117;

int a[N];

void mergeSort (int tl, int tr){
    if (tl == tr){
        return;
    } else {
        int tm = (tl + tr) / 2;
        mergeSort(tl, tm);
        mergeSort(tm + 1, tr);
        int it1 = tl, it2 = tm + 1, pos = 0;
        int* b = new int[N];
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
                if (a[it1] < a[it2]){
                    b[pos] = a[it1];
                    it1++;
                } else {
                    b[pos] = a[it2];
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
        delete[] b;
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
