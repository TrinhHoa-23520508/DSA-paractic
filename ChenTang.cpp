#include <iostream>

using namespace std;
#define MAXN 150000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void ChenTang(int x, int a[], int& n) {
    if (n == 0) {
        a[0] = x;
        n = 1;
    }
    else if (x >= a[n - 1]) {
        a[n] = x;
        n++;
    }
    else if (x <= a[0]) {
        for (int i = n; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = x;
        n++;
    }
    else {
        int index = -1;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (a[middle] < x) {
                left = middle + 1;
                index = left;
            }
            else if (a[middle] > x) {
                right = middle - 1;
                index = right + 1;
            }
            else {
                index = middle;
                break;
            }
        }
        for (int i = n; i > index; i--) {
            a[i] = a[i - 1];
        }
        a[index] = x;
        n++;
    }
}

void XuatMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN];
    int x; cin >> x;
    int n; cin >> n;

    NhapMang(a, n);

    ChenTang(x, a, n);

    XuatMang(a, n);

    return 0;
}


