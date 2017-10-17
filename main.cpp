#include <iostream>
#include <cassert>

using namespace std;

template <class T>
void msort(T a[], T x[], int s, int e) {
    if(e - s < 1) return;
    int m = (s + e) / 2;
    int i, j, k;
    i = s;
    j = m +1;
    k = 0;

	msort<T>(a, x, s, m);
	msort<T>(a, x, m + 1, e);

    while (i <= m && j <= e) {
        if (a[i] < a[j]) {
            x[k++] = a[i++];
        }
        else {
            x[k++] = a[j++];
        }
    }
    while (i <= m) {
        x[k++] = a[i++];
    }
    while (j <= e) {
        x[k++] = a[j++];
    }
    for (i = s; i <= e; i++) {
        a[i] = x[i - s];
    }
}

template <class T>
void mergesort(T a[], int n) {
    T * x = new T[n];
    msort(a, x, 0, n - 1);
    delete []x;

}

template <class T>
bool sorted(T a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
   	return true;
}

int main(int argc, char * args[]) {
	double a[] = { 2.2, -9.4, 122.11, 45, -7, 33, -7, 16, 99, 21 };
	mergesort<double>(a, 10);
	assert(sorted<double>(a, 10));

	cout << "All tests passed." << endl;	
}
