#include <stdio.h>

int main() {
    int i;
    int min;
    int min1;
    int tmp;
    int n=0;
    scanf("%d", &n);
    int mass[n];
    for (i=0;i<n;i++){
        scanf("%d", &mass[i]);
    }
    if (mass[0]<mass[1]){              //вот эта рокировка минимальных ее надо понять лучше
        min=mass[0];
        min1=mass[1];
    } else {
        min1 = mass[0];
        min = mass[1];
    }
    for (i=2;i<n;i++) {
        if (mass[i] < min) {
            min1 = min;
            min = mass[i];
        } else if (mass[i] < min1)
            min1 = mass[i];
    }
    if (min1 < min) {
        min1 = tmp;
        min1 = min;
        min = tmp;
    }

    printf("%d ", min);
    printf("%d", min1);
    return 0;
}
