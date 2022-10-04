#include "Sort.h"

void Merge(int* A, int p, int q, int r){ //A - масив. p, q, r - індекси. p<=q<r
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = new int[n1+1];
    int* R = new int [n2+1];
    int i, j;
    for (i = 0; i < n1; i++)
        L[i] = A[p+i-1];
    for (j = 0; j < n1; j++)
        R[j] = A[q+j];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    for (int k = p-1; k < r; k++){
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i += 1;
        }
        else {
            A[k] = R[j];
            j += 1;
        }
    }
}

void MergeSort(int* A, int p, int r){ //A - масив. p, r - індекси.
    if (p < r){
        int q = floor((p+r)/2);
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

void Show(int* A, int n){
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int GetMax(int* A, int n){
    int max = A[0];
    for (int i = 1; i < n; i++){
        if (max < A[i])
            max = A[i];
    }
    return max;
}

void CountingSort(int* A, int n, int exp){
    int *B = new int[10];
    int* C = new int[10];
    for (int i = 0; i <= 10; i++)
        C[i] = 0;
    for (int j = 0; j < n; j++) {
        C[(A[j]/exp) % 10] += 1;
    }
    for (int i = 1; i < 10; i++)
        C[i] += C[i-1];
    for (int j = n-1; j >= 0; j--){
        B[C[(A[j]/exp) % 10]-1] = A[j];
        C[(A[j]/exp) % 10]--;
    }
    for (int i = 0; i < n; i++){
        A[i] = B[i];
    }
}

void RadixSort(int* A, int n){
    int max = GetMax(A, n);
    for (int exp = 1; max/exp > 0; exp*=10)
        CountingSort(A, n, exp);
}
