#include <bits/stdc++.h>
#define MAXn 1000000
using namespace std;
double *a = new double[MAXn];

void qs(int L, int H)
{
    int i = L, j = H; double x = a[(L+H)/2];
    do
    {
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j)
        {
            double tam = a[i]; a[i] = a[j]; a[j] = tam;
            i++; j--;
        }
    } while (i<=j);
    if (L<j) qs(L,j);
    if (i<H) qs(i,H);
}

int main()
{
    cout<<"[Quick Sort] \n";
    string dau = "DATA", cuoi = ".TXT";
    for (int k = 1; k <= 10; k++)
    {
        string giua = to_string(k), file = dau + giua + cuoi;
        ifstream nhap(file);
        for (int i = 0; i < MAXn; i++) nhap>>a[i];
        clock_t start = clock();
        qs(0,MAXn-1);
        clock_t end = clock();
        double time_elapsed = double(end - start);
        cout << "DATA " << k << ": " << time_elapsed << " ms" << "\n";
    }
    return 0;
}
