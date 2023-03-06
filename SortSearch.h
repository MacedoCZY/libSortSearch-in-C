#include <stdbool.h>

typedef int Tdado;
typedef unsigned Tsize;

void troca(Tdado *x, Tdado *y);

void bubbleSort(Tdado *dados, Tsize n);

void shakerSort(Tdado *dados, Tsize n);

void selectionSort(Tdado *dados, Tsize n);

void insertionSort(Tdado *dados, Tsize n);

void shellSort(Tdado *dados, Tsize n);

void merge(Tdado *V, Tsize lo, Tsize mid, Tsize hi);

void mergeGort(Tdado *V, Tsize lo, Tsize hi);

Tsize partition(Tdado *V, Tsize lo, Tsize hi);

void quickSort(Tdado *V, Tsize lo, Tsize hi);

Tsize seqSearch(Tdado e, Tdado *V, Tsize n);

Tsize binSearch(Tdado e, Tdado *V, Tsize n);
