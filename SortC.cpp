#include <bits/stdc++.h>
#define MAXn 1000000

using namespace std;
double *a = new double[MAXn];

int main()
{
    cout<<"[Sort Function in C++] \n";
    string dau = "DATA", cuoi = ".TXT";
    for (int k = 1; k <= 10; k++)
    {
        string giua = to_string(k), file = dau + giua + cuoi;
        ifstream nhap(file);
        for (int i = 0; i < MAXn; i++) nhap>>a[i];
        clock_t start = clock();
        sort(a,a+MAXn);
        clock_t end = clock();
        double time_elapsed = double(end - start);
        cout << "DATA " << k << ": " << time_elapsed << " ms" << "\n";
    }
}
