#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *a, int esq, int dir);
 
int main(int argc, char** argv){
    clock_t start, end;
    double cpu_time_used = 0.0;
    start = clock();

    int i, MAX;
    printf("Digite o tamanho do vetor: ");
    scanf ("%d",&MAX);
    int v[MAX];
 
    for(i = 0; i < MAX; i++){
        printf("Digite um valor: ");
        scanf("%d", &v[i]);
    }

    quicksort(v, 0, MAX - 1);
 

    for(i = 0; i < MAX; i++){
        printf("%d ", v[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf ("\nTEMPO: %f ", cpu_time_used);
    return 0;
}
 
void quicksort(int *a, int esq, int dir) {
    int i, j, x, y;
     
    i = esq;
    j = dir;
    x = a[(esq + dir) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < dir) {
            i++;
        }
        while(a[j] > x && j > esq) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        quicksort(a, esq, j);
    }
    if(i < dir) {
        quicksort(a, i, dir);
    }
}