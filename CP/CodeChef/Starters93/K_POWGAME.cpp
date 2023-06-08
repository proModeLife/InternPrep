#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int z= n%(k+1);
        if (z % 2 == 1 or z==k)printf("Shivansh\n");
        else printf("Tina\n");
    }

    return 0;
}