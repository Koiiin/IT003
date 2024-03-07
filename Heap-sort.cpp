#include <bits/stdc++.h>
#define MAXn 1000000
using namespace std;
double *a = new double[MAXn];

void sw(double &x, double &y)
{
    double tam = x; x = y; y = tam;
}
void taoheap(int N, int i)
{
	int largest = i, l = 2 * i + 1, r = 2 * i + 2;
	if (l < N && a[l] > a[largest]) largest = l;
	if (r < N && a[r] > a[largest]) largest = r;
	if (largest != i)
    {
		sw(a[i], a[largest]); taoheap(N, largest);
	}
}
void heapSort(int N)
{
	for (int i = N / 2 - 1; i >= 0; i--) taoheap(N, i);
	for (int i = N - 1; i > 0; i--)
    {
		sw(a[0], a[i]); taoheap(i, 0);
	}
}
int main()
{
	cout<<"[Heap Sort] \n";
    string dau = "DATA", cuoi = ".TXT";
    for (int k = 1; k <= 10; k++)
    {
        string giua = to_string(k), file = dau + giua + cuoi;
        ifstream nhap(file);
        for (int i = 0; i < MAXn; i++) nhap>>a[i];
        clock_t start = clock();
        heapSort(MAXn);
        clock_t end = clock();
        double time_elapsed = double(end - start);
        cout << "DATA " << k << ": " << time_elapsed << " ms" << "\n";
    }

}
