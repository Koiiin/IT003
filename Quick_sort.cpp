#include <bits/stdc++.h>
#define MAXn 1000000

using namespace std;

double *arr = new double[MAXn];

void QuickSort(int Low, int High)
{
    double index = arr[(Low + High) / 2];
    do
    {
        while (arr[Low] < index) {
            Low++;
        }
        while (arr[High] > index) {
            High--;
        }
        if (Low <= High)
        {
            swap(arr[Low], arr[High]);
            Low++; 
            High--;
        }
    } while (Low <= High);

    if (Low < High) {
        QuickSort(Low, High);
    }
    if (Low < High) {
        QuickSort(Low, High);
    }
}

int main()
{
    cout<<"Quick Sort: " << '\n';
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
        QuickSort(0, MAXn-1);
        clock_t end = clock();
        double time_elapsed = double(end - start);
        cout << "Quick " << k << " : " << time_elapsed << " ms" << "\n";
    }
    return 0;
}
