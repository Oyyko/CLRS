#include <iostream>

using namespace std;

const int inf = 0xffffff;

void Merge(int *A, int p, int q, int r)
{
    int B[q + 1 - p + 1];
    int C[r - q + 1];
    B[q + 1 - p] = inf;
    C[r - q] = inf;
    for (int i = 0; i <= q - p; ++i)
    {
        B[i] = A[i + p];
    }
    for (int i = 0; i <= r - q - 1; ++i)
    {
        C[i] = A[i + q + 1];
    }
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; ++k)
    {
        if (B[i] <= C[j])
            A[k] = B[i++];
        else
            A[k] = C[j++];
    }
}

void MergeSort(int *A, int p, int r) //A[p,r]
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;

        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r); //Merge A[p,q] and A[q+1,r], which are both sorted}
    }
}

int main()
{
    int A[100];
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &A[i]);
    }
    MergeSort(A, 1, n);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

}