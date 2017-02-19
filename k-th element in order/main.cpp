#include <bits/stdc++.h>

using namespace std;

const int N = (int)3e7 + 17;

int a[N];

int cut (int l, int r){
    int m = (l + r) / 2;
    swap(a[l], a[m]);
    int j = l;
    for (int i = l + 1; i <= r; i++){
        if (a[i] <= a[l]){
            swap(a[i], a[j + 1]);
            j++;
        }
    }
    swap(a[l], a[j]);
    return j;
}

int findK (int n, int k){
    int l = 0, r = n - 1;
    k--;
    while (true){
        if (r - l <= 1){
            if (r - l == 1 && a[r] < a[l])
                swap(a[l], a[r]);
            return a[k];
        }
        int m = cut(l, r);
        if (m == k)
            return a[k];
        if (m < k){
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
}

int kth(int l,int r,int k)
{
    int x = a[(l+r) / 2];
    int i=l,j=r;
    while(i<=j)
    {
        while(a[i] < x) i++;
        while(a[j] > x) j--;

        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(l<=k && k<=j)
        return kth(l,j,k);
    if( i<=k && k<=r)
        return kth(i,r,k);
    return a[k];
}

int main()
{
//    freopen("input.txt", "r", stdin);
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    int n, k, ans, A, B, C;
    scanf("%d%d", &n, &k);
//    for (int i = 0; i < n; i++){
//        scanf("%d", &a[i]);
//    }
    scanf("%d%d%d%d%d", &A, &B, &C, &a[0], &a[1]);
    for (int i = 2; i < n; i++){
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    }
    ans = kth(0, n - 1, k - 1);
    printf("%d", ans);
    return 0;
}
