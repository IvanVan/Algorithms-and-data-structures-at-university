#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100 * 1000 + 23;
 
int a[N];
 
int main()
{
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++){
        if (2 * i <= n && a[i] >= a[2 * i]){
            printf("NO");
            return 0;
        }
        if (2 * i + 1 <= n && a[2 * i + 1] < a[i]){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
