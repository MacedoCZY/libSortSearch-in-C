#include <limits.h>
#include "SortSearch.h"

void troca(Tdado *x, Tdado *y)
{
    Tdado aux = *x;
    *x = *y;
    *y = aux;
}

void bubbleSort(Tdado *dados, Tsize n)
{
    for(Tsize i = 0; i < (n - 1); i++)
        for(Tsize j = (n - 1); j > i; j--)
            if(dados[j] < dados[j - 1])
                troca(&dados[j], &dados[j - 1]);
}

void shakerSort(Tdado *dados, Tsize n)
{
    bool trocou;

    do
    {
        trocou = false;
        
        for(Tsize i = (n - 1); i > 0; i--)
        {
            if(dados[i - 1] > dados[i])
            {
                troca(&dados[i - 1], &dados[i]);
                trocou = true;
            }
        }
        for(Tsize i = 1; i < n; i++)
        {
            if(dados[i - 1] > dados[i])
            {
                troca(&dados[i - 1], &dados[i]);
                trocou = true;
            }
        }    
    }while(trocou);
}

void selectionSort(Tdado *dados, Tsize n)
{
    for(Tsize i = 0; i < (n - 1); i++)
    {
        Tsize min = i;
        for(Tsize j = i + 1; j < n; j++)
           if(dados[j] < dados[min])
                min = j;
        troca(&dados[min], &dados[i]);    
    } 
}

void insertionSort(Tdado *dados, Tsize n)
{
    for(Tsize i = 1; i < n; i++)
    {
        Tdado aux = dados[i];
        Tsize j = 0;
        for(j = i; (j > 0) && aux < dados[j - 1]; j--)
            dados[j] = dados[j - 1];
        dados[j] = aux;
    }
}

void shellSort(Tdado *dados, Tsize n)
{
    Tsize i, j, gap, k;
    Tdado x;
    Tsize a[5] = {9, 5, 3, 2, 1};

    for(k = 0; k < 5; k++)
    {
        gap = a[k];
        for(i - gap; i < n; i++)
        {
            x = dados[i];
            for(j = 1 - gap; x < dados[j] && j >= 0; j -= gap)
                dados[j + gap] = dados[j];
            dados[j + gap] = x;
        }
    }
}

void merge(Tdado *V, Tsize lo, Tsize mid, Tsize hi)
{
    Tsize n1 = mid - lo + 1;
    Tsize n2 = hi  - mid;
    Tdado left[n1 + 1], right[n2 +1];
    Tsize i = 0, j = 0;
        
    for(i = 0; i < n1; i++)
        left[i] = V[lo + i];

    for(j = 0; j < n2; j++)
        right[j] = V[mid + 1 + j];
    
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;

    for(Tsize k = lo; k <= hi; k++)
        if(left[i] <= right[j])
            V[k] = left[i++];
        else
            V[k] = right[j++];
}

void mergeSort(Tdado *V, Tsize lo, Tsize hi)
{
    if(lo < hi)
    {
        Tsize mid = (lo + hi)/2;
        mergeSort(V, lo, mid);
        mergeSort(V, mid + 1, hi);
        merge(V, lo, mid, hi);
    }
}

Tsize partition(Tdado *V, Tsize lo, Tsize hi)
{
    Tsize pivo = V[(lo + hi)/2];
    Tsize i = lo - 1, j = hi + 1;
    while(1)
    {
        do
        {
            i++;
        }while(V[i] < pivo);
        do
        {
            j--;
        }while(V[i] > pivo);
        if(i >= j)
            return j;
        troca(&V[i], &V[j]);
    }
}

void quickSort(Tdado *V, Tsize lo, Tsize hi)
{
    if(lo < hi)
    {
        Tsize pivo = partition(V, lo, hi);
        quickSort(V, lo, pivo);
        quickSort(V, pivo + 1, hi);
    }    
}

Tsize seqSearch(Tdado e, Tdado *V, Tsize n)
{
    Tsize i;
    for(i = 0; i < n && V[i] != e; i++)
    if(i == n)
        return -1;
    else
        return i;
}

Tsize binSearch(Tdado e, Tdado *V, Tsize n)
{
    Tsize lo = 0, hi = n - 1, i = 0;
    while(lo <= hi)
    {
        i = (lo + hi)/2;
        if(V[i] == e)
            return i;
        if(e < V[i])
            hi = i - 1;
        else
            lo = i + 1;
    }
    return - 1;
}
