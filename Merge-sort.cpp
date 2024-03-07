#include <bits/stdc++.h>
#define MAXn 1000000
using namespace std;
double *a = new double[MAXn];

void gop(int l, int m, int r)
{
    int i, j, k;
    double *left = new double[m - l + 1]; double *right = new double[r - m];
    for (i = 0; i < m - l + 1; i++) left[i] = a[l + i];
    for (j = 0; j < r - m; j++) right[j] = a[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < m - l + 1 && j < r - m)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i]; i++;
        } else
        {
            a[k] = right[j]; j++;
        }
        k++;
    }
    while (i < m - l + 1)
    {
        a[k] = left[i]; i++; k++;
    }
    while (j < r - m)
    {
        a[k] = right[j]; j++; k++;
    }
}
void mergeSort(int l, int r)
{
    if (l < r) {
    int m = l + (r - l)/2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    gop(l, m, r);
  }
}

int main()
{
    cout<<"[Merge Sort] \n";
    string dau = "DATA", cuoi = ".TXT";
    for (int k = 1; k <= 10; k++)
    {
        string giua = to_string(k), file = dau + giua + cuoi;
        ifstream nhap(file);
        for (int i = 0; i < MAXn; i++) nhap>>a[i];
        clock_t start = clock();
        mergeSort(0, MAXn - 1);
        clock_t end = clock();
        double time_elapsed = double(end - start);
        cout << "DATA " << k << ": " << time_elapsed << " ms" << "\n";
    }
    return 0;
}

