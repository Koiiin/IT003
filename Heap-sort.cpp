#include <bits/stdc++.h>
#define MAXn 1000000

using namespace std;

double *arr = new double[MAXn];

void ChangeSit(double &x, double &y)
{
    swap(x, y);
}

void CreateHeap(int N, int i)
{
	int imp = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
	if (left < N && arr[left] > arr[imp]) {
        imp = left;
    }

	if (right < N && arr[right] > arr[imp]) {
        imp = right;
    }

	if (imp != i) {
		ChangeSit(arr[i], arr[imp]); 
        CreateHeap(N, imp);
	}
}

void heapSort(int N)
{
	for (int i = N / 2 - 1; i >= 0; --i) {
        CreateHeap(N, i);
    }

	for (int i = N - 1; i > 0; --i) {
		ChangeSit(arr[0], arr[i]); 
        CreateHeap(i, 0);
	}
}

int main()
{
	cout<<"Heap Sort: " << '\n';
    string HEAD = "DATA";
    string TAIL = ".TXT";
    for (int k = 1; k <= 10; ++k)
    {
        string BODY = to_string(k);
        string file = HEAD + BODY + TAIL;
        ifstream Input(file);

        for (int i = 0; i < MAXn; ++i) {
            Input >> arr[i];
        }

        clock_t start = clock();
        heapSort(MAXn);
        clock_t end = clock();
        double time_elapsed = double(end - start);
        cout << "Heap " << k << " : " << time_elapsed << " ms" << "\n";
    }

    return 0;
}
