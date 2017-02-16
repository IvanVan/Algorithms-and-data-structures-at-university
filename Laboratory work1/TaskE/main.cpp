#include <bits/stdc++.h>
#include <malloc.h>

using namespace std;
int sz = 2, have = 1;

char* a = (char*)(malloc(2 * sizeof(char)));

void add (char x){
    if (have == sz + 1){
        char* b = (char*)(malloc(2 * sz * sizeof(char)));
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

char pop (){
    if (have <= 1){
        return '1';
    }
    char get = a[have-2];
    have--;
    return get;
}

void cler (){
    a = (char*)(malloc(2 * sizeof(char)));
    have = 1;
    sz = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("input.txt", "r", stdin);
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    while (cin){
        bool flag = true;
        string s;
        cin >> s;
        if (s.size() == 1){
            flag = false;
        }
        if (s == "\n" || s == ""){
            return 0;
        }
        for (int i = 0; i < (int)s.size(); i++){
            if (s[i] == '(' || s[i] == '['){
                add(s[i]);
            } else {
                int get = pop();
                if (get == '(' && s[i] == ')'){
                    //isok
                } else if (get == '[' && s[i] == ']'){
                    //isok
                } else {
                    flag = false;
                }
            }
        }
        if (flag && have <= 1){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        cler();
    }
    return 0;
}
