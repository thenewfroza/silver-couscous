#include <stdio.h>

int main() {

    int i;
    int N=0;

    int temp;
   scanf("%d", &N);
    int mass[N];
    for (i=0; i<N; i++){
        scanf("%d", &mass[i]);
    }
    temp= mass[N-1];
    for (i=N-1;i>=0; i--){
        mass[i]=mass[i-1];
    }
    mass[0]=temp;
    for (i=0; i<N; i++){
        printf(" %d", mass[i] );
    }
    return 0;
}
// работает только для N=4