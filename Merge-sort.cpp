#include <bits/stdc++.h>
#define MAXn 1000000

using namespace std;

double *arr = new double[MAXn];

void MergeLs(int l, int m, int r)
{
    double *left = new double[m - l + 1];
    double *right = new double[r - m];
    for (int i = 0; i < m - l + 1; i++) {
        left[i] = arr[l + i];
    }

    for (int j = 0; j < r - m; j++) {
        right[j] = arr[m + 1 + j];
    }
    
    int i = 0; 
    int j = 0; 
    int k = l;

    while (i < m - l + 1 && j < r - m)
    {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j]; 
            j++;
        }
        k++;
    }

    while (i < m - l + 1) {
        arr[k] = left[i]; 
        i++; 
        k++;
    }

    while (j < r - m) {
        arr[k] = right[j];
        j++; 
        k++;
    }
}
void mergeSort(int l, int r)
{
    if (l < r) {
    int m = l + (r - l)/2;
    mergeSort(l, m);
    mergeSort(m + 1, r);
    MergeLs(l, m, r);
  }
}

int main()
{
    cout<<"Merge Sort: " << '\n';
    string HEAD = "DATA", TAIL = ".TXT";
    for (int k = 1; k <= 10; ++k)
    {
        string BODY = to_string(k);
        string file = HEAD + BODY + TAIL;
        ifstream Input(file);
        for (int i = 0; i < MAXn; i++) {
            Input >> arr[i];
        }
        clock_t start = clock();
        mergeSort(0, MAXn - 1);
        clock_t end = clock();
        double time_elapsed = double(end - start);
        cout << "Merge " << k << " : " << time_elapsed << " ms" << "\n";
    }
    return 0;
}

