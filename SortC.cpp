#include <bits/stdc++.h>
#define MAXn 1000000

using namespace std;
double *arr = new double[MAXn];

int main()
{
    cout<<"C++ Sort: " << '\n';
    string HEAD = "DATA";
    string TAIL = ".TXT";
    for (int k = 1; k <= 10; ++k)
    {
        string BODY = to_string(k);
        string file = HEAD + BODY + TAIL;
        ifstream Input(file);
        for (int i = 0; i < MAXn; i++) {
            Input >> arr[i];
        }
        clock_t start = clock();
        sort(arr, arr+MAXn);
        clock_t end = clock();
        double time_elapsed = double(end - start);
        cout << "C++ sort " << k << " : " << time_elapsed << " ms" << "\n";
    }
}
